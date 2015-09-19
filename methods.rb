$the_alphabet = "abcdefghijklmnopqrstuvwxyz"
def rearrange(key)
  array_crypt = $the_alphabet.split('')
  for i in 0..(key - 1)
    temp1 = array_crypt[i]
    array_crypt.push(temp1)
  end
  array_crypt.last(26).join
end
def encrypt(key, phrase) #encryption method
  phrase.tr("a-z",rearrange(key)).tr("A-Z",rearrange(key).upcase)
end
def decrypt(key, phrase) #decryption method
  phrase.tr(rearrange(key),"a-z").tr(rearrange(key).upcase,"A-Z")
end