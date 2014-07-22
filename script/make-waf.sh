wget http://ftp.waf.io/pub/release/waf-1.7.16.tar.bz2
tar xvjf waf-1.7.16.tar.bz2
cd waf-1.7.16
python waf-light  --make-waf --tool=swig
