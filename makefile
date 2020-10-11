.PHONY : all clean

# 命令
CXX := g++
MKDIR := mkdir
RM := rm -rf

# 库和头文件
INCS := -I/usr/local/include 
LIBS := -L/usr/local/lib -lzmq -lpthread

# FLAGS
CXXFLAGS = -g -Wall -std=c++11
LDDFLAGS = 

# 源码
SRCPUB = publisher.cpp
SRCSUB = subscriber.cpp
SRCPS = pubsub.cpp

# 依赖
OBJPUB := $(SRCPUB:.cpp=.o)
OBJSUB := $(SRCSUB:.cpp=.o)
OBJDPS := $(SRCPS:.cpp=.o)

TARGET := publisher subscriber pubsuber

all : $(TARGET)
	@echo compile finished

%.o : %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS) $(INCS)

publisher : $(OBJPUB)
	$(CXX) $^ -o $@ $(LDDFLAGS) $(LIBS)

subscriber : $(OBJSUB)
	$(CXX) $^ -o $@ $(LDDFLAGS) $(LIBS)

pubsuber : $(OBJDPS)
	$(CXX) $^ -o $@ $(LDDFLAGS) $(LIBS)

clean:
	$(RM) $(TARGET) $(OBJPUB) $(OBJSUB) $(OBJDPS)



