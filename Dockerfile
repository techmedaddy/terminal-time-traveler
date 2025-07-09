FROM gcc:12

WORKDIR /app

COPY . .

RUN apt-get update && apt-get install -y nlohmann-json3-dev

RUN make

CMD ["./bin/time_traveler"]
