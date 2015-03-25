Pod::Spec.new do |s|

s.name             = "UberKit"
s.version          = "0.1.0"
s.summary          = "A simple, easy-to-use Objective C wrapper for the Uber API."
s.homepage         = "https://github.com/joshim5/UberKit"
s.license          = { :type => 'MIT', :text => 'Copyright 2014 Sachin Kesiraju, modified 2015 by Joshua Meier' }
s.author           = { "Joshua Meier" => "jmeier@college.harvard.edu" }
s.source           = { :git => "https://github.com/joshim5/UberKit.git", :tag => '0.1.0'}
s.social_media_url = "https://twitter.com/joshim5"
s.platform     = :ios, '7.0'
s.requires_arc = true
s.source_files = 'UberKit', 'UberKit/**/*.{h,m}'


end
