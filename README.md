
# Socket Programming in C

Socket programming is a concept where two or more users can talk to each other; it can be through video calls or text chatting.

#### Two types of sockets which i learned.
    1. TCP (Transmission Control Protocol)
    2. UDP (User Datagram Protocol)


### TCP
Transmission Control Protocol is referred to as a “SOCK_STREAM,” which is reliable. A connection-based socket means that if we are using TCP, we have to build the first connection with the user before we can send data or receive data and it's very slow. Also, it's error-free and when we want to use socket for chating app and calling we can use TCP.


### UDP 
User Datagram Protocol which is referred to as a "SOCK_DGRAM" which is not reliable it's also called a connectionless socket it used for gaming and striming why it's not reliable becouse if it get any error your data will lost at the same time it's very fast.


## Data Encapsulation
Data encapsulatation is the important topics it's all about when we are sending data and after that how intrernet is sending data in a simple way data Encapsulation is the process where data wraped based on layers Protocol.


                 
#### There are 7 Layers of data Encapsulation.

    1. Application - User (we) writes or sends data.
    2. Presentation - Data encrypted/compressed for security.
    3. Session - Connection established between sender and receiver
    4. Transport - It breaks data into small parts called pakets also give a secquence no for eact packte so data can collect in correct order and add a port number.
    5. Network - it adds the IP(Internet Protocol) address for source and destination
    6. Data Link - It adds a mac address to the data for communication to the local network.
    7. Physical - It converts data in bites and sends it through cables or wireless signals.



## Data Decapsulation
In the data decapsulation data travels in the same but reverse order that's called data dencapsulation.

    1. Physical - It converts data in bites and sends it through cables or wireless signals.  
    2. Data Link - It adds a mac address to the data for communication to the local network.  
    3. Network - It adds the IP(Internet Protocol) address for source and destination.  
    4. Transport - It breaks data into small parts called packets, also gives a sequence number for each packet so data can collect in the correct order and adds a port number.  
    5. Session - Connection established between sender and receiver.  
    6. Presentation - Data encrypted/compressed for security.  
    7. Application - User (we) writes or sends data.



## Kernel
It's a main part of an operating system it's like the brain and heart of our OS, it's like a manager who handles all low-level tasks in our computer, it connects software to hardware it's like a bridge.

    1. Process Management
    2. Memory Management
    3. File System Management
    4. Network Communication
    5. Security and Access Control


## IP address
IP Addresses are unique identifiers which is located to each devise like (phone, computer, fan, tv etc...).

#### IPv4 VS IPv6 

IPv4 - is writen in four bytes just doted desimal for ex:  ``` 192.0.2.111 ```

IPv6 - It uses 128 bits (compared to 32 bits in IPv4) which is write in hexadecimal representation. 
Ex: ``` 2001:0db8:c9d2:aee5:73e3:934a:a5ae:9551```

 
#### Why we need IPv6 when we had IPv4
Now, we live in a time where we are talking about everyone having an IP address, and this includes not just people, but also every computer, phone, calculator, parking meter.

That's why we need a lot more addresses, we’re talking powers here: (IPv4) 32 bits represents some 4 billion numbers (232), while (IPv6) 128 bits represents about 340 trillion trillion trillion numbers (for real, 2128). That’s like a million IPv4 Internets for every single star in the Universe.


    Note - you’ll have an IP address with lots of zeros in it, and you can compress them between two colons.


### Subnet
Subnet is the divisions of IP addresses called subnet, like we can break a IP address in two part frist one is Network port and second one is Host part.
    
    IP address - 192.0.2.12
    Network Part - 192.0.2
    Host Part - 12



## Port Numbers
The port number. It’s a 16-bit number that’s like the local address for the connection, for exapmle IP address as the street address of a hotel, and the port number as the room number.

For HTTP (the web) is port 80, ports under 1024 are often considered special, and usually require special OS privileges to use.

    Ex: https://www.google.com/


### Byte Order
When data is stored in memory, it can be stored in two ways:

    1. Big-Endian (or Network Byte Order)
    2. Little-Endian (or Host Byte Order)
```Note -```
Big-Endian means big-end of the number is stored first, for example you have 1234 it will store 34 frist and Little-Endian means little end" first so 12 will store frist.

#### When you're sending data over the internet (like in packets), everyone agreed to use Big-Endian (Network Byte Order) because it's a common standard.

### How to convert data?

You can use every combination of “n”, “h”, “s”, and “l” you want, not counting the really stupid ones. For example, there is NOT a stolh() (“Short to Long Host”) function—not at this party, anyway. But there are:

    Function <----------->	Description

    htons()	host to network short

    htonl()	host to network long

    ntohs()	network to host short

    ntohl()	network to host long
    
    
## struct (Structure)
It is a user-defined data type in C that allows grouping together variables of different data types into a single unit. It is used to represent a record or complex data structures.

    struct addrinfo {
        int              ai_flags;     // AI_PASSIVE, AI_CANONNAME, etc.
        int              ai_family;    // AF_INET, AF_INET6, AF_UNSPEC
        int              ai_socktype;  // SOCK_STREAM, SOCK_DGRAM
    };


    inet_pton() is for converting from string to binary (presentation to network).
    ex:
    struct sockaddr_in sa;
    inet_pton(AF_INET, "10.12.110.57", &(sa.sin_addr));


    inet_ntop() is for converting from binary to string (network to presentation).
    ex:
    struct sockaddr_in6 sa6;
    inet_pton(AF_INET6, "2001:db8:63b3:1::3490", &(sa6.sin6_addr));


## Pointers

Pointers are variables that store the memory address of another variable.

ex:

    int a = 10;
    int *p = &a;

1. Address-of Operator (&) : Returns the memory address of a variable.
2. Dereference Operator (*): Accesses the value at the memory address stored in the pointer.

### Private IP Address

Private IP addresses are reserved for use within private networks and are not routable on the public internet. Some common private IP address ranges include:


### Librearyes

    <stdin.h>  --> Input/Output.
    <string.h> --> For string like copy string and compaire.
    <stdlib.h> --> Memory related work.
    <unistd.h> --> For file descriptor (read() and close()).
    <arpa/inet.h> --> IP related work.
    <sys.socket.h> --> For Socket.



## Socket
It used to create a socket.

### How to create socket:
    Server:                        Client:


    Socket()                       Socket()
        |                             | 
     Bind()                           |
        |                          Connetct()      
    Listen()                          |  
        |                             |
    Accept()                          |
        |                             |
    Send/Recv  <--------------->  Send/Recv  



### Socket():
socket() function is used to create a socket which returns a file descriptor if socket is created else error.

Syntax:

    int socket(int domain, int type, int protocol);

    domain: It can be AF_INET (IPv4) or AF_INET6 (IPv6) 
    type: Specifies the type of socket (SOCK_STREAM or SOCK_DGRAM).
    protocol: 0 used to the default protocol.


### Bind():
Bind() associate a socket with a specific IP address and port number it returns 0 on succesfull and -1 on error.

Syntax:

    int bind(int sockfd, const struct sockaddr *addr, ocklen_t *addrlen);

    sockfd: It called File descriptor socket() function return it.
    struct sockaddr *addr: It's specifies the IP address and port to bind.
    ocklen_t *addrlen: The size of the struct sockaddr addr.

    INADDR_ANY: Binds the socket to any available network;


## Listen():
it will accept incoming connection requests from clients it returns 0 on success and -1 on error.

Syntax:

    int listen(int sockfd, int backlog);

    sockfd: It called File descriptor socket() function return it.
    backlog: Maximum number of pending connections allowed in the queue before the server starts.


Socket is concidered is a active(Initiates connections) but after using listen it become passive(Means it waites when client will connect). 


## Accept():
This function accept an incoming connection request from a client.

Syntax:

    int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    
    sockfd: A file descriptor of the passive socket created.
    struct sockaddr *addr: A pointer who hold IP address and port.
    socklen_t *addrlen: holds the size of the addr structure.



### Important Functions:

    memset(): Used to fill a block of memory with a specific value.
    
    char buffer[1024];
    memset(buffer, 0, BUFFER_SIZE);


    close(): Closes a file descriptor.
    close(server_fd);


    fgets(): Reads a string from the specified input
    fgets(buffer, BUFFER_SIZE, stdin);


## send() and read():
These functions allow sending and receiving data between two connected users. 

### send():

Syntax:

    send(new_socket, buffer, strlen(buffer), 0);

    new_socket: A file descriptor of the passive socket created.
    buffer: Massage which we want to send.
    strlen(buffer): Length of the massage.
    0: Set to 0 for default behavior.



### read():

Syntax:

    read(new_socket, buffer, BUFFER_SIZE)

    new_socket: A file descriptor of the passive socket created.
    buffer: Massage which we want to send.
    BUFFER_SIZE: Length of the massage.


### close():
It used to close file descriptor.

Syntax:

    close(sock);

    sock: A file descriptor of the passive socket created.
    

### Client-Server Model:
The client-server model is a fundamental concept where two diffrent things (server and client) communicate together it's a backbone of modern network-based applications.


#### Steps:

    1. Client starts to connect to the server.
    2. The client sends a request to the server.
    3. Server process the request and prepares the response.
    4. server sends the requested data back to the client.
    5. After communication is complete, the connection is closed.


#### Protocols:
    1. TCP (Transmission Control Protocol): Slower communication but data is secure.
    2. UDP (User Datagram Protocol): Faster communication but data can lost.
    3. HTTP/HTTPS: For web Application.



### perror() and strerror():

    perror(): Prints an error message.
    perror("Socket failed");



    strerror(): Returns a pointer to a string containing the error message.
    *strerror(int errnum);




### exit():
The exit() function is used to terminate a program.

ex:

    exit(EXIT_FAILURE);






## For running the programme:

Before starting the steps on your computer it must have GCC.


### Step-1:

Make a clone of this repo - 
    https://github.com/rishavtiwari22/socket.git


### Step - 2:
    
    Run the commands

    For server 
    gcc server.c -o server
    ./server


    For client
    gcc client.c -o client
    ./client






