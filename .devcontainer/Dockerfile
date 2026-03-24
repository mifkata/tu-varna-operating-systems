FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    gcc g++ make binutils autoconf automake cmake pkg-config \
    gdb strace ltrace linux-headers-generic libtool m4 bison flex \
    git patch diffutils build-essential \
    zsh curl wget less man-db nano vim \
    openssh-client ca-certificates locales

# Set up locale
RUN locale-gen en_US.UTF-8
ENV LANG=en_US.UTF-8

# Create dev user
RUN useradd -m -s /bin/zsh dev

USER dev
ENV HOME=/home/dev
RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

WORKDIR /workspace

CMD ["zsh"]
