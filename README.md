#README for libsocket

##LICENSE

It's recommended to compile libsocket statically into your program (by placing the .c and .h files in your source tree).
You don't have to mind legal issues because libsocket is licensed by a slightly modified 2-clause BSD license which permits
any use, as long as you include the license text in your product (so it's clear that libsocket is licensed by this License)
and the notice that *we* wrote libsocket (as described in the license)
It's nice to mention libsocket in your product's Readme or advertisements anyway, of course :)

##USE

libsocket is built for little programs whose author(s) are too lazy to build own algorithms and functions for socket (UNIX
and Internet Domain (TCP/UDP)) communication.

As you should know as experienced C programmer, it's quite easy to use this library.
Simply add the line into the source files where the library is used:

	# include "path/to/lib{inet,unix}socket.h"

and call the compiler (eventually in a makefile) with the name of the C file:

	$ gcc lib{inet,unix}socket.c ownfile1.c ownfile2.c
	# or
	$ gcc -c libsocket.c
	$ gcc ownfile1.c ownfile2.c libsocket.o
	# etc. pp.

##FEATURES AND ADVANTAGES

The libsocket library supports following things and protocols:

* IPv4 (client, server)
* IPv6 (client, server; if your machine supports it)
* TCP (client, server)
* UDP (client, server)
* UNIX Domain Sockets (DGRAM&STREAM server/client), only for Linux
* Intelligent algorithms to get the best connection and no errors
* Easy use (one function call to get a socket up and running, one another to close it)
* Proper error processing (using `errno`, `gai\_strerror()` etc.).

One of the main advantages of libsocket is that you don't have to write the complex and error-prone
procedures for connecting a socket, check it for errors etc. yourself. Your network programs
get shorter and better readable.

libsocket supports almost every socket types. During there is no useful documentation, take a look
at the header files in headers/. Most of the functions are self-explaining.

Almost every syscall is wrapped by libsocket, e.g.:
	- sendto
	- recvfrom
	- accept
	- socket/connect - one function
	- socket/bind    - one function

If you're wondering about the UNIX DGRAM functions: Yes, `create_unix_dgram_socket("path")` and `create_unix_server_socket("path",DGRAM,...)`
produces the same result. DGRAM sockets are alway server and client at the same time. The difference is good to distinguish
semantically between the sockets in your code.

If you want to have even more control over the sockets you're using, this library is not the right tool for you. It's intended for the easy
use of sockets.

For detailed documentation read DOCUMENTATION.md resp. DOCUMENTATION.html

##EXAMPLES

You may test libsocket and make some experiences by playing with the examples provided in the standard libsocket distribution
in examples/.
The collection of examples contain:

* http.c: A simple http client
* echo\_reconnect.c, echo\_srv.c: Less echo server than simple transmit of text using INET UDP sockets, but also showing the use of `reconnect_isocket()`
* unix\_stream\_client.c, unix\_stream\_server.c: Demonstrating UNIX STREAM sockets as echo server/client
* unix\_dgram\_client.c, unix\_dgram\_server.c: Demonstrating UNIX DGRAM sockets as simple server/client transmitting text.

You should have a look at the length of the code; while `http.c` is complete with 24 sloc (source lines of code) - the quite similar client
simple-http (https://github.com/dermesser/Simple-HTTP-client) uses almost 70 lines of code.

##PLATFORMS

libsocket is developed on Linux 3.x with gcc, but every file was successfully tested with clang (from llvm 3.0) and works with it.

Unfortunately, libinetsocket won't work on OpenBSD anymore after the rewrite. On Linux, everything's fine.

##REWRITE

Since e1688a6, the library was almost completely rewritten. The process is completed with tag `rewrite_complete_ii`.
The new library is more reliable, clear and functional. If the old library works in your programs, there's no cause
to migrate to the new library, but for new programs, the new library is recommended, especially the libunixsocket part.
