wget https://waf.io/waf-1.8.16.tar.bz2
tar xvjf waf-1.8.16.tar.bz2
cd waf-1.8.16
python waf-light  --make-waf --tool=swig
