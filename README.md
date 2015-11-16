# Caesar_Cipher

This is a basic Caesar Cipher script that allows you to shift the letters in a phrase by any key 1-25. 
I have also included a script to decrypt messages without the key. 

Now with commandline options! 
	
	-k for key
	-m for phrase

Just added a less feature-filled, but faster, version coded in Rust.

Currently, you use it like so:

To encrypt: 
	
	ruby /path/to/caesar-cipher.rb encrypt -k <key> -m "<message>"
	
To decrypt: 

	ruby /path/to/caesar-cipher.rb decrypt -k <key> -m "<message>"

To brute-decrypt:

	ruby /path/to/caesar-cipher.rb brute-decrypt -m "<message>"
