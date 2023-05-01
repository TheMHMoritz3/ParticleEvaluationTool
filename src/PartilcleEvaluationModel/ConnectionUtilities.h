//
// Created by moritzh on 25.10.22.
//

#ifndef CONANFILE_PY_CONNECTIONUTILITIES_H
#define CONANFILE_PY_CONNECTIONUTILITIES_H

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>


namespace Model {


    class ConnectionUtilities {


    private:

        unsigned int Port = 0;
    };

} // Model

#endif //CONANFILE_PY_CONNECTIONUTILITIES_H
