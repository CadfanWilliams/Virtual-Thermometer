FROM gcc:13 AS builder

WORKDIR /app

COPY . .

RUN g++ -std=c++17 -O2 -Wall -Wextra -pedantic \
    src/main.cpp TemperatureReadingGenerator.cpp \
    -o thermometer

FROM debian:stable-slim

WORKDIR /app

RUN apt-get update && apt-get install -y \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

COPY --from=builder /app/thermometer .

RUN useradd -m appuser
USER appuser

CMD ["./thermometer"]