#include <cmath>

#include <cmath>
#include <MatrixMath.h>

void calculateXYZ(double R, double G, double B, double& X, double& Y, double& Z) {
    double matrix[3][3] = {
        {0.412453, 0.357580, 0.180423},
        {0.212671, 0.715160, 0.072169},
        {0.019334, 0.119193, 0.950227}
    };

    double input[3] = {R, G, B};
    double output[3];
    
    MatrixMath matrixMath;
    matrixMath.Multiply((double*)matrix, input, 3, 3, 1, output);

    X = output[0];
    Y = output[1];
    Z = output[2];
    X = X/(X+Y+Z);   
    Y = Y/(X+Y+Z);
}
