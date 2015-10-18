use std::io;

fn encrypt(input: String, key: i16) -> String {
	// parse the inputted string into bytes
	let mut vector_input = input.into_bytes();
	// iterate through the entire Vector to adjust UTF values
	for v in &mut vector_input {
		if *v >= 65 && *v <= 90 {		
			*v = (key + (*v as i16)) as u8;
			if *v > 90 {
				*v = 65 + (*v - 91);
			} else if *v < 65 {
				*v = 90 - (64 - *v);
			}
		} else if *v >= 97 && *v <= 122 {		
			*v = (key + (*v as i16)) as u8;
			if *v > 122 {
				*v = 97 + (*v - 123);
			} else if *v < 97 {
				*v = 122 - (96 - *v);
			}
		}
	}
	// replace the original with the encrypted...
	let input = String::from_utf8(vector_input)
		.ok()
		.expect("Something went wrong");
	// return the string back to the user, encrypted.
	return input;
}
fn decrypt(input: String, key: i16) -> String {
	return encrypt(input, (key * -1));
}
fn main() {
	println!("Enter a value to encrypt");
	// declare variable to hold user input
	let mut user_input = String::new();
	// Get input from user for text to encrypt
	io::stdin().read_line(&mut user_input)
		.ok()
		.expect("Error: Invalid Input");

	println!("Now enter a key to encrypt on");
	// Here, we declare a String to hold user's input for key
	let mut key = String::new();
	// Get input from user for key
	io::stdin().read_line(&mut key)
		.ok()
		.expect("Error: Invalid Input");
	// parse and convert key String to integer
	let mut key: i16 = key.trim().parse()
		.ok()
		.expect("Invalid Key");
	// convert key to a value between 0 and 25, and make key immutable
	if key >= 26 {
		key -= 26
	}
	let mut encrypted = encrypt(user_input, key);
	println!("{}", encrypted);

	println!("{}", decrypt(encrypted, key));
}