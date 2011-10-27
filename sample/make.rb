#!/usr/bin/env ruby
`nkf -w --overwrite *.c`
sources = Dir.glob('*.c') - Dir.glob('test-*.c')
sources.each do |s|
  puts "--- #{s} ---"
  puts `gcc #{s} -o #{s.gsub(/\.c$/, '')}`
end
