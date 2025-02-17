all:
	g++ -std=c++17 testJWT.cpp -lcppunit -o testJWT
test:
	chmod +x testJWT
clean:
	$(RM) testJWT
