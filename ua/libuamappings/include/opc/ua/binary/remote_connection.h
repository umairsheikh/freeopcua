/// @author Alexander Rykovanov 2012
/// @email rykovanov.as@gmail.com
/// @brief Opc binary cnnection channel.
/// @license GNU GPL/LGPL
///
/// Distributed under the GNU GPL/LGPL License
/// (See accompanying file LICENSE or copy at 
/// http://www.gnu.org/copyleft/gpl.html)
///
/// $Id:  $
/// $Date: $
/// $Revision: $

#ifndef __OPC_UA_BINARY_CHANNEL
#define __OPC_UA_BINARY_CHANNEL

#include <opc/ua/channel.h>

#include <memory>
#include <string>

namespace OpcUa
{
  namespace Binary
  {
 
    class RemoteConnection : public IOChannel
    {
    public:
       virtual std::size_t Receive(char* data, std::size_t size) = 0;
       virtual void Send(const char* message, std::size_t size) = 0;

       virtual std::string GetHost() const = 0;
       virtual unsigned GetPort() const = 0;
    };


    std::unique_ptr<RemoteConnection> Connect(const std::string& host, unsigned port);

  } // nmespace Bunary
} // namespace OpcUa

#endif // __OPC_UA_BINARY_CHANNEL

