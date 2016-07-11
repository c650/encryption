/****************************************************************************

	Charles Bailey

	caesar.swift

	It encrypts/decrypts a phrase according to a certain caesar cipher key.

****************************************************************************/
import Foundation
/*
	Encryption Function:

	Takes a key and mutates any alphabetical character by it. 
	
	Note: lines 29 and 32 hopefully can be trimmed

*/
func encrypt(key: Int, phrase: String) -> String {

	let key = key % 26 // very important to get key within 0-25 range!
	var arr = [Character]() // make an Array ("collection") to store encryped result phrase

	for character in phrase.unicodeScalars { // iterate throught each UnicodeScalar in phrase
		if character.value >= 65 && character.value <= 90 { // check if capital Alpha
			// append to arr: get the UnicodeScalar of the current character + key + 7 (for some reason)
			// mod it by 26 to get it within Alpha range, add 65 to get it to ASCII Alpha range
			arr.append(Character(UnicodeScalar(((Int(character.value) + key + 7) % 26) + 65)))			
		} else if character.value >= 97 && character.value <= 122 { // check if lower Alpha
			// see ln25-26; same except for the lower case
			arr.append(Character(UnicodeScalar(((Int(character.value) + key + 7) % 26) + 97)))			
		} else {
			// just append the original if it isn't alphabetical
			arr.append(Character(character))
		}
	}

	// return a String composed of the array from ln21
	return String(arr)
}
/*
	
	Decryption Function:

	Simply calls encrypt(...) with a negated key.

*/
func decrypt(key: Int, phrase: String) -> String {
	return encrypt(-key, phrase: phrase)
}
/*

	"main()"

	The controller for the program.

*/
if Process.arguments.count != 2 {
	// ln 57-60: check for correct number of arguments
	print("\nWrong number of arguments.")
	print("Usuage: caesar <key>")
} else {
	print("Put in the phrase to encrypt: ") // prompt for input, duh
	if let input = readLine() { // will exit if getting a string fails
		if let key = Int(Process.arguments[1]) { // assigns the key, exits if fails
			// ln67-71: presents user with the results
			print("Encrypting...")
			print(encrypt(key, phrase: input))

			print("Decrypting...")
			print(decrypt(key, phrase: encrypt(key, phrase: input)))
		} // curly brace
	} // another curly
} // i'm just trolling