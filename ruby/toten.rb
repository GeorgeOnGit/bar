#!/usr/bin/ruby
#Given an array, return indexes of two elements that add up to 10.
a = [0,1,2,3,4,5,6,7,8,9]
puts a.join(" ")
 v = Hash.new
 a.each_index do | i |
  v[10-a[i]] ? puts("#{i} and #{v[10-a[i]]} ") : v[a[i]] = i
 end
