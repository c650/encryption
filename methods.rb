#declare alphabet just because
$the_alphabet ="abcdefghijklmnopqrstuvwxyz"
$keywords = ["mine","the","if","of","me","you","on","off","first","last","maybe","yes","no","it","but","that","this","there","their","they"]
#encryption method
def encrypt(key, phrase)
  array_crypt = $the_alphabet.split('')
  key -= 1
  for i in 0..key
    temp1 = array_crypt[i]
    array_crypt.push(temp1)
  end
  array_crypt = array_crypt.last(26)
  new_alpha = array_crypt.join
  phrase = phrase.tr($the_alphabet, new_alpha)
  phrase = phrase.tr($the_alphabet.upcase, new_alpha.upcase)
  return phrase
end
#decryption method
def decrypt(key, phrase)
  array_crypt = $the_alphabet.split('')
  key -= 1
  for i in 0..key
    temp1 = array_crypt[i]
    array_crypt.push(temp1)
  end
  array_crypt = array_crypt.last(26)
  new_alpha = array_crypt.join
  phrase = phrase.tr(new_alpha, $the_alphabet)
  phrase = phrase.tr(new_alpha.upcase, $the_alphabet.upcase)
  return phrase
end