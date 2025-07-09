# Use GCC base image
FROM gcc:12

# Set working directory
WORKDIR /app

# Copy project files into the container
COPY . .

# Install required JSON library
RUN apt-get update && apt-get install -y nlohmann-json3-dev

# Build the project and list output
RUN make clean && make && ls -la bin/

# Set the default command to run your CLI app
CMD ["./bin/time_traveler"]
