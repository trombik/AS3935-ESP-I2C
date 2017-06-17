desc "Generate doxygen XML"
task :doxygen do
  sh "doxygen"
end

desc "Generate markdown document from doxygen XML"
task :doc => [:doxygen] do
  Dir.mkdir("docs/md") unless Dir.exist?("docs/md")
  sh "nodejs node_modules/moxygen/bin/moxygen.js --output docs/md/README.md docs/xml"
end

desc "Install moxygen to current directory"
task :install_moxygen do
  sh "npm install moxygen"
end
