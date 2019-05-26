

#include "gofmain.h"


Product::Product() 
{ 
	ProducePart(); 
	cout<<"return a product"<<endl; 
} 

Product::~Product() 
{ 
	
} 

void Product::ProducePart() 
{ 
	cout<<"build part of product.."<<endl; 
} 

ProductPart::ProductPart()
{ 
	//cout<<"buildproductpart.."<<endl; 
} 

ProductPart::~ProductPart() 
{ 
} 

ProductPart* ProductPart::BuildPart()
{ 
	return new ProductPart; 
} 





