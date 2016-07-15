module Vigenere
	def Vigenere.encrypt(str, key)
		k = Array.new(key.length, 0)

		for i in 0...key.length
			k[i] = key[i].downcase[0].ord - 'a'.ord
		end

		i = 0
		s = []
		str.each_byte do |c|
			if c.chr =~ /[[:alpha:]]/
				if c.chr == c.chr.downcase
					s << ((c - 'a'.ord + k[i % key.length]) % 26 + 'a'.ord).chr
				elsif c.chr == c.chr.upcase
					s << ((c - 'A'.ord + k[i % key.length]) % 26 + 'A'.ord).chr
				end
				i+=1
			else
				s << c.chr
			end
		end

		return s.join('')
	end

	def Vigenere.decrypt(str,key)
		k = []
		key.each_byte do |c|
			k << ('z'.ord - (c.chr.downcase.ord - 'a'.ord - 1)).chr
		end

		return encrypt(str,k.join(''))
	end
end