#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <fstream>

// WriteToFile will be doing the writing of the sampled data to a .csv file
void WriteToFile(){
    std::cout << "Name of file to save (Leave off file extensions, its going to be a .csv whether you like it or not):";
    std::string saveFileInput;
    std::cin >> saveFileInput;
    std::string saveFileName = saveFileInput + ".csv"; //Make sure the file will be a .csv
    std::ofstream myfile;
    myfile.open(saveFileName.c_str());
    if (myfile.is_open()){
        //Do the writing in here    
        myfile << "This is the first cell in the first column.\n";
        myfile << "a,b,c,\n";
    } else {
        //Something went wrong if you're here
        std::cout << "Unable to open file" << std::endl;
    }

    //Mission accomplished the file was written to
    std::cout << "The file " << saveFileName << " has been saved" << std::endl;

    //Close the file to prevent more writing
    myfile.close();
}


int main() {

    std::cout << "Welcome to the Serial Reader, got milk?" << std::endl;

    /* Set up the control structure */
    struct termios options;

    //fd is a file descriptor
    int fd;
    int err = 0;
    
    std::string usbLocationInput;
    //Reimplement these later
    // std::cout << "Enter path to USB:";
    // std::cin >> usbLocationInput;
    std::string usbLocation = "/dev/cu.usbserial-1420" + usbLocationInput;

    //Open a connection on the serial port
    fd = open(usbLocation.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
    printf("fd opened as %i\n", fd);    //Mainly a troubleshooting thing

    char buf[256];

    // It turns out this sleep is pretty important. From what I vaguely remember
    // is that Arduinos do an autoreset on power up and this can cause weird
    // problems and so it's a good idea to just wait a second or two.
    sleep(2);

    if (fd == -1) {
        std::cout << "unable to open serial port..." << std::endl;
        std::cout << "err : " << strerror(errno) << std::endl;
    }

    std::cout << "configuring the port..." << std::endl;
    /* Get currently set options for the tty */
    tcgetattr(fd, &options);
    /* set to 9600 baud */
    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);

    /* enable receiver, ignore status lines */
    options.c_cflag |= (CLOCAL | CREAD);
    /* no hardware flow control */
    options.c_cflag &= ~CRTSCTS;
    //options.c_iflag = IGNPAR | ICRNL;
    //options.c_oflag = 0;

    /* 8 bits, no parity, no stop bits */
    options.c_cflag &= ~PARENB;
    options.c_cflag |= PARODD;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;
    //options.c_iflag |= (INPCK | ISTRIP);

    /* disable input/output flow control, disable restart chars */
    options.c_iflag &= ~(IXON | IXOFF | IXANY);
     /* disable canonical input, disable echo,
    disable visually erase chars,
    disable terminal-generated signals */
    options.c_oflag &= ~(ICANON | ECHO | ECHOE | ISIG);

    /* disable output processing */
    options.c_oflag &= ~OPOST;
    /* commit the options */
    tcsetattr(fd, TCSANOW, &options);

    /* Wait for the Arduino to reset */
    usleep(1000*1000);
    /* Flush anything already in the serial buffer */
    tcflush(fd, TCIFLUSH);
    err = fcntl(fd, F_SETFL, FNDELAY);
    if (err == -1) std::cout << "err #: " << strerror(errno) << std::endl;

     /* read up to 128 bytes from the fd */
    int n = read(fd, buf, 64);
    printf("%i bytes got read...\n", n);

    /* print what's in the buffer */
    printf("Buffer contains...\n%s\n", buf);
    std::cout << buf << std::endl;

    //TODO: Try this stuff later?
    err = read(fd, buf, 8);
    if (err == -1) std::cout << "err #: " << strerror(errno) << std::endl;
    std::cout << "Rx'd: " << std::hex << buf << std::endl;

    std::cout << "Closing serial connection..." << std::endl;
    err = close(fd);
    if (err == -1) std::cout << "err #: " << strerror(errno) << std::endl;

    return 0;
}
