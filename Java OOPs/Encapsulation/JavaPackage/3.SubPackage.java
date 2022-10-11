/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
  
  /*
  	Program: In this section we will learn about the subpackage in java packages.
		
	Subpackage: Package inside the package is called the subpackage. it should
	by created to categorize the package further.

	Note: The standard of defining package is domain.company.package e.g 
	com.virst.main or org.sssit.dao etc.
  */
  
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
  

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
  
package com.virst.physic;

class Vector{  
  public static void main(String args[]){  
   System.out.println("This is Vector class from subpackage");  
  }  
}  
  
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/
/*-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-*/


/*----------------------------------------------
: compile ----> javac -d . 3.SubPackage.java
: run     ----> java com.virst.physic.Vector
----------------------------------------------*/