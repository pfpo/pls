rm -rf ../pls-release/pls
cp -r pls ../pls-release/
cd .. && rm -rf pls-release.zip 
zip -r pls-release.zip pls-release