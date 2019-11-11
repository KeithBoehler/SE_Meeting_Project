# Makefile

# Project Path is the root for this project. In my machine.
PROJECT_PATH=/Users/keithnator3000/OneDrive\ -\ The\ University\ of\ Texas-Rio\ Grande\ Valley/Classes/STEM/Computer_Science/Software\ Engineering\ I\ -\ CSCI\ 3340/SE_Fall19/project/SE_Meeting_Project
CXX=/usr/local/Cellar/gcc/9.2.0/bin/g++-9
LDFLAGS=-L/usr/local/opt/mysql-client/lib -lsqlite3
#CPPFLAGS=-I/usr/local/opt/mysql-client/include -I/usr/local/opt/mysql-client/include -lmysqlclient
CPPFLAGS=-I/usr/local/opt/mysql-client/include -I/usr/local/opt/mysql-client/include \
					-I$(PROJECT_PATH)/include/

%.o : %.cpp
	$(CXX) -o $@ -c $< $(CPPFLAGS)

master: master.o Database.o
	$(CXX) -o ./..$($PROJECT_PATH)/bin/master.out $+ $(LDFLAGS)

clean:
	rm ./../bin/*
	rm *.o

.PHONY: clean
