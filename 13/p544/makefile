# 컴파일러 및 옵션
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

# 현재 디렉터리의 모든 .cpp 파일 목록
SOURCES  := $(wildcard *.cpp)
# .cpp 파일을 대응하는 .o 파일로 변환
# OBJECTS  := $(SOURCES:.cpp=.o)

# 최종 실행 파일 이름
TARGET   := main

# 기본 타겟: make 또는 make all 입력 시 실행
all: $(TARGET)

# 실행 파일 생성 규칙
# $(TARGET): $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) -o $@ $^

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 각 .cpp 파일을 .o 파일로 컴파일
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# 불필요한 파일 삭제 (make clean)
# $(OBJECTS)
clean:
	rm -f $(TARGET)

.PHONY: all clean