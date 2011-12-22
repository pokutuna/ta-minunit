#!/usr/bin/env ruby
require 'optparse'
require 'open3'
OPTS = {}
opt = OptionParser.new.on('-t', '--target=FILE', 'specify target file') { |v| OPTS[:target] = v }
opt.parse!(ARGV)

target = OPTS.include?(:target) ? OPTS[:target] : '*.c'
test = Dir.glob('test-*.c')
sources = Dir.glob(target) - test
sources.each do |s|
  puts "--# #{s} #--"
  `nkf -w --overwrite #{s}`
  `gcc -fPIC -shared #{s} -o lib#{s.gsub(/\.c$/, '')}.so` if $?.success?
  `gcc #{test.join(' ')} lib#{s.gsub(/\.c$/, '')}.so -o t-#{s.gsub(/\.c$/, '')}` if $?.success?
  `./t-#{s.gsub(/\.c$/, '')}` if $?.success?
  puts ''
end
