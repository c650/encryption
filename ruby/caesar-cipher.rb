require 'colored'
require 'trollop'
require_relative "./methods.rb"
require_relative "./decryption_brute_force.rb"
SUB_COMMANDS = %w(encrypt decrypt brute-decrypt)
opts = Trollop::options do
  	banner "Encrypt/Decrypt Caesar Cipher"
  	opt :phrase, "Specify the phrase to encrypt/decrypt.", :short => "-m", :type => :string
  	opt :key, "Specify the key to encrypt/decrypt with.", :short => "-k", :type => :int, :default => 0
end
cmd = ARGV.shift.to_s.downcase
unless opts[:phrase]
	puts "No phrase was inputted. Exiting..."
	exit
end
if cmd == "encrypt"
	puts encrypt(opts[:key],opts[:phrase])
elsif cmd == "decrypt"
	puts decrypt(opts[:key],opts[:phrase])
elsif cmd == "brute-decrypt"
	brute_decrypt(opts[:phrase])
end