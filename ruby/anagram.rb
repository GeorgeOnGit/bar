#!/usr/bin/ruby
require 'yaml'
#Give a dictory file and a in put string
#Find out all dictionary words that are made of letters in the input string.
#i.e. X is a letter, x belongs to input string and x belongs to B, where B is the resulting set of dictionary words. 

#1. read in dictory a txt file.
 dictionary = File.open("dictionary.txt")

#2. build dick_hash[:word]=> word.alphabetize
 dic_hash = Hash.new
 dictionary.each do | line |
  line.scan(/\w+/).each do | word |
   word = word.downcase
   dic_hash[word] ||= word.each_char.sort.join.squeeze
  end
 end 
#3. reverse dick_hash build anagram[:ordered_string] = {words made of this charactors} 
 anagram = Hash.new
 dic_hash.each_pair do |key, value|
  anagram[value] = anagram[value] ? (anagram[value] << key) : Array[key]
 end
#4. sort input, print out anagrams
 while true do
 puts "type in some letters:"
 letters = gets.chomp.downcase.each_char.sort.join.squeeze
 puts "Here are words made of #{letters}:"
 puts anagram[letters] ? anagram[letters].join("++") : "_____No Results_______"
 end
