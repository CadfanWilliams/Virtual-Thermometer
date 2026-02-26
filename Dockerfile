FROM gcc:13

WORKDIR /app
COPY . .

RUN g++ src/main.cpp -o thermometer

CMD ["./thermometer"]