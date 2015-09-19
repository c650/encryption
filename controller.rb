require "colored"
require_relative "./methods.rb"
key = rand(26) + 1
puts "Enter a message:".red
phrase = gets.chomp
puts "Encrypted:".red
puts (encrypt(key,phrase))