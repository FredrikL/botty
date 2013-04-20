require 'socket'

server = TCPServer.new 6667
loop do
  client = server.accept
  begin
	  client.puts "Hello !"
	  while line = client.gets
	  	puts line
	  end
	  client.close
  rescue Exception => e
  	
  end
end