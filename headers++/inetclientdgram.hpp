# ifndef INETSOCKET
# define INETSOCKET

# include <string>
# include <sys/types.h>
# include <sys/socket.h>
# include "socket.hpp"
# include "inetbase.hpp"
# include "inetdgram.hpp"

# define TCP 1
# define UDP 2

# define IPv4 3
# define IPv6 4

# define BOTH 5 // what fits best (TCP/UDP or IPv4/6)

# define READ 1
# define WRITE 2

# define NUMERIC 1

// Quite simple oo wrapper around libinetsocket

namespace libsocket
{
	using std::string;

	class inet_dgram_client : public inet_dgram
	{
		private:
		bool connected;

		public:

		// Only create socket
		inet_dgram_client(int proto_osi3,int flags=0); // Flags: socket()
		// Create socket and connect it
		inet_dgram_client(const char* dsthost, const char* dstport, int proto_osi3, int flags=0); // Flags: socket()

		// actions
		// connect/reconnect
		void connect(const char* dsthost, const char* dstport);
		void deconnect(void);

		// I/O
		// O
		// only if connected
		friend inet_dgram_client& operator<<(inet_dgram_client& sock, const char* str);
		friend inet_dgram_client& operator<<(inet_dgram_client& sock, string& str);

		ssize_t snd(const void* buf, size_t len, int flags=0); // flags: send()

		// I
		friend inet_dgram_client& operator>>(inet_dgram_client& sock, string& dest);

		ssize_t rcv(void* buf, size_t len, int flags=0);

		// Getters

		bool getconn(void);
	};

}
# endif
