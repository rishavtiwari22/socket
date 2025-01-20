
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
        int              ai_protocol;  // use 0 for "any"
        size_t           ai_addrlen;   // size of ai_addr in bytes
        struct sockaddr *ai_addr;      // struct sockaddr_in or _in6
        char            *ai_canonname; // full canonical hostname

        struct addrinfo *ai_next;      // linked list, next node
    };


    inet_pton() is for converting from string to binary (presentation to network).
    ex:
    struct sockaddr_in sa;
    inet_pton(AF_INET, "10.12.110.57", &(sa.sin_addr));


    inet_ntop() is for converting from binary to string (network to presentation).
    ex:
    struct sockaddr_in6 sa6;
    inet_pton(AF_INET6, "2001:db8:63b3:1::3490", &(sa6.sin6_addr));



#### Private IP Address

Private IP addresses are reserved for use within private networks and are not routable on the public internet. Some common private IP address ranges include:





