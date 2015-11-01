#include <iostream>
#include <boost/asio.hpp>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <string>

void print(const boost::system::error_code& /*e*/,std::string str)
{
    std::cout << str << "\n";
}

int main()
{
    boost::asio::io_service io;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(10));
    boost::function<void (const boost::system::error_code&)> func = boost::bind(&print, _1, std::string("Hi there"));
    t.async_wait(func);
    io.run();

    return 0;

}
