//============================================================================
// Name        : project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
int main();
void interval_calculator();

int main() {
	interval_calculator();
	return 0;
}
void interval_calculator()
{
	double intermediate_a = -1;
	double intermediate_b = -2;
	double stored_x = -1;
	double stored_y = -2;
	std::string command;
	while(true){
		std::cout << "input :> ";
		std::cin >> command;
		if(command == "exit"){
			std::cout << "Bye bye: Terminating interval calculator program.";
			return;
		}
		else if(command == "enter")
		{
			double a = 0;
			double b = 0;
			std::cin>>a>>b;
			if (a<=b)
			{
				intermediate_a = a;
				intermediate_b = b;
				std::cout <<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			}
			else{
				std::cout<<"Error: invalid interval as " <<a <<" > "<<b<<std::endl;
				if (intermediate_a != -1 || intermediate_b !=-2)
				{
					std::cout <<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
				}
				else
				{
					std::cout<<"--"<<std::endl;
				}
			}
		}
		else if (command == "negate")
		{
			if(intermediate_a!=-1||intermediate_b !=-2)
			{
				std::cout<<"["<<-intermediate_b<<", "<<-intermediate_a<<"]"<<std::endl;
			}
			else{
				std::cout<<"--"<<std::endl;
			}
		}
		else if (command == "invert")
		{
			if (intermediate_a * intermediate_b <=0)
			{
				std::cout<<"Error: division by zero"<<std::endl;
				intermediate_a =-1;
				intermediate_b =-2;
			}
			if(intermediate_a!=-1||intermediate_b !=-2)
			{
				std::cout <<"["<<1/intermediate_b<<", "<<1/intermediate_a<<"]"<<std::endl;
			}
			else
			{
				std::cout<<"--"<<std::endl;
			}
		}
		else if(command == "ms")
		{
			if(intermediate_a!= -1 || intermediate_b != -2){
			                std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			                stored_x =  intermediate_a;
			                stored_y =  intermediate_b;
			            }else{
			                std::cout<<"--"<<std::endl;
			            }
		}
		else if(command =="mr")
		{
			if (intermediate_a!= -1 || intermediate_b != -2){
			    if (stored_x!=-1 || stored_y!=-2){
			        intermediate_a = stored_x;
			        intermediate_b = stored_y;
			    }
			    std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			    }
			    else{
			       std::cout<<"--"<<std::endl;
			                }
		}
		else if(command == "mc")
		{
			stored_x=-1;
			stored_y=-2;
			if (intermediate_a == -1 || intermediate_b == -2){
			    std::cout<<"--"<<std::endl;
			}
			else{
			    std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			   }
	    }
		else if (command == "m+")
		{
			if ((intermediate_a!=-1 || intermediate_b!=-2)||(stored_x!=-1||stored_y!=-2))
			 {stored_x =intermediate_a + stored_x;
			  stored_y =intermediate_b + stored_y;
			}
			 if (intermediate_a==-1 && intermediate_b==-2){
			 	std::cout<<"--"<<std::endl;
			 }else{
			 	std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			 }
		}
		else if (command == "m-")
		{
			if ((intermediate_a!=-1 || intermediate_b!=-2)||(stored_x!=-1||stored_y!=-2)){
				stored_x=stored_x-intermediate_a;
				stored_y=stored_y-intermediate_b;
				}
			if (intermediate_a==-1 && intermediate_b==-2){
				std::cout<<"--"<<std::endl;
			}else{
					std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			}
		}
		else if (command == "scalar_add")
		{
			double c{};
			std::cin>>c;
			if (intermediate_a!=-1 || intermediate_b!=-2){
			    intermediate_a=intermediate_a+c;
			    intermediate_b=intermediate_b+c;
			    std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			}else{
				std::cout<<"--"<<std::endl;
			}
		}
		else if (command == "scalar_subtract")
		{
			double c{};
			std::cin>>c;
			if (intermediate_a!=-1 || intermediate_b!=-2){
				intermediate_a=intermediate_a-c;
				intermediate_b=intermediate_b-c;
				std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			}else{
				std::cout<<"--"<<std::endl;
			}
		}
		else if (command == "scalar_multiply")
		{
			double c{};
			std::cin>>c;
			if (command == "scalar_multiply"){
			    if (intermediate_a!=-1 || intermediate_b!=-2){
			        if (c>0){
			            intermediate_a=intermediate_a*c;
			            intermediate_b=intermediate_b*c;
			            std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			        }else{
			            double temp=intermediate_a;
			            intermediate_a=intermediate_b*c;
			            intermediate_b=temp*c;
			             std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			        }
			     }else{
			           std::cout<<"--"<<std::endl;
			     }
		}
		}
		else if (command == "scalar_divide")
		{
			double c{};
			std::cin>>c;
			if (intermediate_a!=-1 || intermediate_b!=-2){
			    if (c>0){
			        intermediate_a=intermediate_a/c;
			        intermediate_b=intermediate_b/c;
			        std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			    }else if(c<0){
			        	double temp1=intermediate_a;
			        	intermediate_a=intermediate_b/c;
			        	intermediate_b=temp1/c;
			        	std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			   }
			   else{
				   std::cout<<"Error: division by zero";
			            	  	intermediate_a=-1;
			            	  	intermediate_b=-2;
			            	  	std::cout<<"--"<<std::endl;
			               }
			}else{
			    std::cout<<"--"<<std::endl;
			}
		}
		else if (command == "scalar_divided_by")
		{
			double c{};
			std::cin>>c;
			if (intermediate_a!=-1 || intermediate_b!=-2){
			    if (intermediate_a*intermediate_b>0){
			        if (c>0){
			           double temp2=intermediate_a;
			           intermediate_a=c/intermediate_b;
			           intermediate_b=c/temp2;
			           std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			        }else{
			               intermediate_a=c/intermediate_a;
			               intermediate_b=c/intermediate_b;
			        std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			        }
			    }else{
			             intermediate_a=-1;
			             intermediate_b=-2;
			             std::cout<<"Error:division by zero"<<std::endl;
			        }
			 }else{
			      std::cout<<"--"<<std::endl;
			 }
		}
		else if (command == "interval_add")
		{
			double c{};
			double d{};
			std::cin>>c>>d;
			if (c>d){
			    std::cout<<"Error: invalid interval as"<<c<<">"<<d<<std::endl;
			    if (intermediate_a == -1 && intermediate_b == -2){
			        std::cout<<"--"<<std::endl;
			    }
			    else{
			         std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			    	}
			    }else{
			         if(intermediate_a!=-1 || intermediate_b!=-2){
			            intermediate_a=intermediate_a+c;
			            intermediate_b=intermediate_b+d;
			            std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			          }
			 else{
			    	std::cout<<"--"<<std::endl;
			    }
		}
		}
		else if (command == "interval_subtract")
		{
			double c{};
			double d{};
			std::cin>>c>>d;
			if (c>d){
			    std::cout<<"Error: invalid interval as"<<c<<">"<<d<<std::endl;
			    if (intermediate_a == -1 && intermediate_b == -2){
			        std::cout<<"--"<<std::endl;
			        }else{
			              std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			              }
			    }else{
			        if(intermediate_a!=-1 || intermediate_b!=-2){
			           intermediate_a=intermediate_a-c;
			           intermediate_b=intermediate_b-d;
			           std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			    }else{
			           std::cout<<"--"<<std::endl;
			    }
		}
	}
		else if (command == "interval_multiply")
		{
			double c{};
			double d{};
			std::cin>>c>>d;
			if (c>d){
			    std::cout<<"Error: invalid interval as"<<c<<">"<<d<<std::endl;
			    if (intermediate_a == -1 && intermediate_b == -2){
			        std::cout<<"--"<<std::endl;
			       }else{
			        std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			       }
			 }else{
			     if (intermediate_a!=-1 || intermediate_b!=-2){
			         double min{};
			         double max{};
			         if (intermediate_a*c < intermediate_a*d){
			             max = intermediate_a*d;
			             min = intermediate_a*c;
			             }else{
			               max = intermediate_a*c;
			               min = intermediate_a*d;
			             }
			         if (max < intermediate_b*c){
			             max = intermediate_b*c;
			         }else if (min > intermediate_b*c){
			          min = intermediate_b*c;
			         }
			         if(max < intermediate_b*d){
			            max = intermediate_b*d;
			         }else if (min>intermediate_b*d){
			            min = intermediate_b*d;
			         }
			         intermediate_a=min;
			         intermediate_b=max;
			         std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			  }else{
			      std::cout<<"--"<<std::endl;
			       }
			 }
		}
		else if (command == "interval_divide")
		{
			double c{};
			double d{};
			std::cin>>c>>d;
			if (c>d){
			    std::cout<<"Error: invalid interval as"<<c<<">"<<d<<std::endl;
			    if (intermediate_a == -1 && intermediate_b == -2){
			        std::cout<<"--"<<std::endl;
			    }else{
			         std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			    	}
			}else{
			    if (c*d<=0){
			        std::cout<<"Error: division by zero"<<std::endl;
			        intermediate_a=-1;
			        intermediate_b=-2;
			     }
			    if (intermediate_a!=-1 || intermediate_b!=-2){
			        double min{};
			        double max{};
			        if (intermediate_a/c < intermediate_a/d){
			            min=intermediate_a/c;
			            max=intermediate_a/d;
			        }else{
			            min=intermediate_a/d;
			            max=intermediate_a/c;
			        }
			     if (min>intermediate_b/c){
			         min=intermediate_b/c;
			     }else if(max < intermediate_b/c){
			              max =  intermediate_b/c;
			     }
			     if (min > intermediate_b/d){
			         min = intermediate_b/d;
			     }else if (max < intermediate_b/d){
			               max = intermediate_b/d;
			     }
			     intermediate_a=min;
			     intermediate_b=max;
			     std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			}else{
			    	std::cout<<"--"<<std::endl;
			    	}
			}
		}else if (command == "intersect")
		{
			double c{};
			double d{};
			std::cin>>c>>d;
			if (c>d){
			    std::cout<<"Error: invalid interval as "<<c<<">"<<d<<std::endl;
			    if (intermediate_a == -1 && intermediate_b == -2){
			        std::cout<<"--"<<std::endl;
			    }else{
			      std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			    }
			}else{
			    if (intermediate_a!=-1 || intermediate_b!=-2){
			        if (c<intermediate_b && d>intermediate_a){
			            if (c>intermediate_a){
			                intermediate_a=c;
			             }
			            if (d<intermediate_b){
			                intermediate_b=d;
			             }
			            std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			         }else {
			             intermediate_a=-1;
			             intermediate_b=-2;
			             std::cout<<"--"<<std::endl;
			         }
			      }else{
			           std::cout<<"--"<<std::endl;
			      }
			 }
	    }
		else if (command == "integers")
		{
			if(intermediate_a!=-1||intermediate_b!=-2)
			{
				int integer = 0;
				if(intermediate_a!=(int)intermediate_a){
					if(intermediate_a>0){
						integer = intermediate_a / 1 + 1;
					}
					else{
						integer = intermediate_a/1;
					}
				}else{
				integer = intermediate_a/1;
					}
			while(integer <= intermediate_b - 1)
			{
				std::cout<<integer<<", ";
				integer++;
			}
				std::cout<<integer;
				std::cout<<std::endl;
				std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
			}
			else{
				std::cout<<"--"<<std::endl;
				}
		}
		else if (command == "cartesian_integers")
				{
					double c{};
					double d{};
					std::cin>>c>>d;
					if(c > d){
					   std::cout<<"Error: invalid interval as "<<c<<" > "<<d<<std::endl;
					   if(intermediate_a == -1 && intermediate_b == -2){
						   std::cout<<"--"<<std::endl;
					   }else{
					      std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
					}
					}else{
					    if(intermediate_a != -1 || intermediate_b != -2){
					     int integer1 = 0;
					     if(intermediate_a != (int)intermediate_a){
					         if(intermediate_a > 0){
					            integer1 = intermediate_a / 1 + 1;
					          }else{
					             integer1 = intermediate_a / 1;
					          }
					     }else{
					           integer1 = intermediate_a;
					     }
					     int integer2{0};
					     if(c != (int)c){
					        if(c > 0){
					           integer2 = c / 1 + 1;
					        }else{
					            integer2 = c / 1;
					        }
					     }else{
					         integer2 = c;
					     }
					     if(integer2 > d || integer1 > intermediate_b){
					         std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
					     }else{
					     for(int m = integer1 ;m <= intermediate_b; ++m){
					         for(int n = integer2;n <= d;++n){
					             if(m != integer1 || n != integer2){
					                std::cout<<", "<<"("<<m<<","<<n<<")";
					         }else{
					              std::cout<<"("<<m<<","<<n<<")";
					         }
					       }
					  }
					   std::cout<<std::endl;
					   std::cout<<"["<<intermediate_a<<", "<<intermediate_b<<"]"<<std::endl;
					  }
					}else{
					     std::cout<<"--"<<std::endl;
					}
					}
				}else{
					std::cout<<"Error: illegal command"<<std::endl;
				}
	}
}









