#include <iostream>
#include <Eigen/Dense>
#include <Eigen/SVD>
double condA(const Eigen::MatrixXd& A)
{
	Eigen::JacobiSVD<Eigen::MatrixXd> svd(A);
	Eigen::VectorXd singularValuesA = svd.singularValues();
	return singularValuesA.maxCoeff() / singularValuesA.minCoeff();
}

void print_vector(const Eigen::VectorXd& vec){
	std::cout<< "[ ";
	for(double el : vec) {
		std::cout<< el << " ";
	}
	std::cout << " ]"<< "\n";
}

  std::pair<Eigen::VectorXd, int> gradiente_coniugato(const Eigen::MatrixXd& A, Eigen::VectorXd x_0, const Eigen::VectorXd& b, const double res_tol){
	Eigen::VectorXd r_0 = b - A*x_0;
	Eigen::VectorXd p_0 = r_0;
	const unsigned int it_max = 1000;
	int it = 0;
	
	while (r_0.norm()>= res_tol && it<=it_max) {
		Eigen::VectorXd Ap = A * p_0; //calcolo una volta per non appesantire
		const double alpha_k = (p_0.dot(r_0))/(p_0.dot(Ap));
		x_0 = x_0 + alpha_k*p_0;
		r_0 = b - A*x_0;
		const double beta_k = (p_0.dot(A*r_0))/(p_0.dot(Ap));
		p_0 = r_0 - beta_k*p_0;
		it++;
	}

	  return std::make_pair(x_0, it);
  }
  
  
  
  int main() 
{
	const double tol = 1.0e-15;
	
	// creo la matrice A, i vettori x_ex e b
	int n = 6;
	Eigen::MatrixXd B = Eigen::MatrixXd::Random(n, n);
	if (abs(B.determinant()) < tol)
		return -1;
	Eigen::MatrixXd A = B.transpose()*B;
	Eigen::VectorXd x_ex = Eigen::VectorXd::Ones(n);
	
	Eigen::VectorXd b = A * x_ex;
	
	Eigen::VectorXd x_0 = Eigen::VectorXd::Zero(n);

	const double res_tol = 1.0e-12;

	std::cout.precision(2);
	std::cout<< std::scientific<< "Matrix Cond: "<< condA(A)<< std::endl;
	
	auto [x_calcolata, it] = gradiente_coniugato(A, x_0, b, res_tol);
	std::cout<< "x calcolata da gradiente_coniugato: ";
	print_vector(x_calcolata);
	std::cout<< "Num iterazioni: " << it << "\n";	


  return 0;
}
