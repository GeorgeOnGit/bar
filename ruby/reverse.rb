#!/usr/bin/ruby 

string = "this is a string"
def reverse string 
a =  string.split(/\s+/)
start, ending = 0, a.size - 1
while start < ending
 a[start], a[ending] = a[ending], a[start] 
 start += 1
 ending -= 1
end
  a.join(" ")
end
 puts "Engers a string:"
 string = gets.chomp
 puts reverse  string

