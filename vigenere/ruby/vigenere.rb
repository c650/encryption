require_relative "./encrypt.rb"

def main()
	s = gets.chomp
	k = gets.chomp

	result = Vigenere.encrypt(s,k)

	puts result

	puts Vigenere.decrypt(result,k)
end

main()