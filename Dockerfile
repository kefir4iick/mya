FROM gcc:latest                  
WORKDIR /usr/src/mya             
COPY dioph.h dioph.cpp test.cpp ./  
RUN g++ -std=c++11 -c dioph.cpp -o dioph.o  
RUN g++ -std=c++11 -c test.cpp -o test.o
RUN g++ dioph.o test.o -o test    
CMD ["./test"]                    
