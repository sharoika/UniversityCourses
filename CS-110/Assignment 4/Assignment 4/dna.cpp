/**
 Student Name: MAKSIM SHAROIKA
 Student Number: 200446763
 Assignment: Assignment 4
 Program Name: dna.cpp
 Date Written: March 27 2021
 Problem Statement: Given the DNA of individuals find which ones have sickle cell anemia (or carry it) and if any of them are related.
 Input: The DNA.txt file will with char's of the DNA sequences of the individuals all in a row
 Output: The DNAanalysis.txt file for the results which include if they have anemia, or are a carrier along with any relations.
*/
/**
 Main Algorithm:
 set a constant int for the gene size,
 create 8 arrays for each gene of each person,
 open files,
 check if files opened,
 extract char's out of input buffer into each gene using loops to max size,
 Loops to look for the 20th positions of each gene and if it contains a 'T', output whether carrier, anemia, or none,
 using samegene function to compare all possible combinations of genes to decide if individuals are related if so output,
 samegene uses loops to compare all positions within 2 genes,
 close files,
 */
/**
 Variables:
 const int GeneSize - 444
 char geneA1 - First gene of person A
 char geneA2 - Second gene of person A
 char geneB1 - First gene of person B
 char geneB2 - Second gene of person B
 char geneC1 - First gene of person C
 char geneC2 - Second gene of person C
 char geneD1 - First gene of person D
 char geneD2 - Second gene of person D
 */
/**
 Program limitations::
 The program is designed with a very specific input file and does not expect any non-char values in the input, the file must be very specific for it to be inputted without any errors.
 */

#include <fstream> // include file streams (buffers)
#include <iostream> // include terminal (mainly for file checks)

using namespace std; // using standard namespace

bool SameGene(char gene1[], char gene2[], int GeneSize); // prototyping a function
void Insert(char &gene, int genesize); // prototyping a function

int main() // the main function
{
    const int GeneSize = 444; // setting the size of a gene as a constant
    
    char geneA1[GeneSize]; // initialize the first gene of A
    char geneA2[GeneSize]; // initialize the second gene of A
    char geneB1[GeneSize]; // initialize the first gene of B
    char geneB2[GeneSize]; // initialize the second gene of B
    char geneC1[GeneSize]; // initialize the first gene of C
    char geneC2[GeneSize]; // initialize the second gene of C
    char geneD1[GeneSize]; // initialize the first gene of D
    char geneD2[GeneSize]; // initialize the second gene of D
    
    ifstream InputFile; // define an input buffer
    ofstream OutputFile; // define an out buffer
    InputFile.open("dna.txt"); // link the input buffer
    OutputFile.open("DNAanalysis.txt"); // link the output buffer
    
    if(!InputFile)
        // checking if the input file failed if so output that and return 1
    {
        cout << "Failed to open input file." << endl; // output the error
        return 1; // return an error code
    }
    if(!OutputFile)
        // checking if the output file failed if so output that and return 2
    {
        cout << "Failed to open output file." << endl; // output the error
        return 2; // return an error code
    }

    for(int i = 0; i < GeneSize; i++)
    // using a loop with gene size to input into first array
    {
        InputFile >> geneA1[i]; // read the gene into the array
    }
    for(int i = 0; i < GeneSize; i++)
    // using a loop with gene size to input into second array
    {
        InputFile >> geneA2[i]; // read the gene into the array
    }
    for(int i = 0; i < GeneSize; i++)
    // using a loop with gene size to input into third array
    {
        InputFile >> geneB1[i]; // read the gene into the array
    }
    for(int i = 0; i < GeneSize; i++)
    // using a loop with gene size to input into fourth array
    {
        InputFile >> geneB2[i]; // read the gene into the array
    }
    for(int i = 0; i < GeneSize; i++)
    // using a loop with gene size to input into fifth array
    {
        InputFile >> geneC1[i]; // read the gene into the array
    }
    for(int i = 0; i < GeneSize; i++)
    // using a loop with gene size to input into sixth array
    {
        InputFile >> geneC2[i]; // read the gene into the array
    }
    for(int i = 0; i < GeneSize; i++)
    // using a loop with gene size to input into seventh array
    {
        InputFile >> geneD1[i]; // read the gene into the array
    }
    for(int i = 0; i < GeneSize; i++)
    // using a loop with gene size to input into eighth array
    {
        InputFile >> geneD2[i]; // read the gene into the array
    }
    
    OutputFile << "Records for sickle-cell anemia:" << endl; // setting up a header for the output file
    
    if(geneA1[19] == 'T' && geneA2[19] == 'T') // checking the if both genes have a T in the 20th position for person A
    {
        OutputFile << "Person A is anemic." << endl; // output that A is anemic
    }
    else if (geneA1[19] == 'T' || geneA2[19] == 'T') // checking if any of the genes have a T in the 20th position for person A
    {
        OutputFile << "Person A is carrier." << endl; // output that A is a carrier
    }
    else
    {
        OutputFile << "Person A is normal." << endl; // if niether are true A is normal
    }
    
    if(geneB1[19] == 'T' && geneB2[19] == 'T') // checking the if both genes have a T in the 20th position for person B
    {
        OutputFile << "Person B is anemic." << endl;  // output that B is anemic
    }
    else if (geneB1[19] == 'T' || geneB2[19] == 'T') // checking if any of the genes have a T in the 20th position for person B
    {
        OutputFile << "Person B is carrier." << endl; // output that A is a carrier
    }
    else
    {
        OutputFile << "Person B is normal." << endl; // if niether are true b is normal
    }
    
    if(geneC1[19] == 'T' && geneC2[19] == 'T') // checking the if both genes have a T in the 20th position for person C
    {
        OutputFile << "Person C is anemic." << endl; // output that C is anemic
    }
    else if (geneC1[19] == 'T' || geneC2[19] == 'T') // checking if any of the genes have a T in the 20th position for person C
    {
        OutputFile << "Person C is carrier." << endl; // output that A is a carrier
    }
    else
    {
        OutputFile << "Person C is normal." << endl; // if niether are true C is normal
    }
    
    if(geneD1[19] == 'T' && geneD2[19] == 'T') // checking the if both genes have a T in the 20th position for person D
    {
        OutputFile << "Person D is anemic." << endl; // output that D is anemic
    }
    else if (geneD1[19] == 'T' || geneD2[19] == 'T') // checking if any of the genes have a T in the 20th position for person D
    {
        OutputFile << "Person D is carrier." << endl; // output that A is a carrier
    }
    else
    {
        OutputFile << "Person D is normal." << endl; // if niether are true D is normal
    }
    
    OutputFile << endl; // end that code block
    
    OutputFile << "Records for genetic relation: " << endl; // setting up a header for the output file
    
    if(SameGene(geneA1, geneB1, GeneSize) || SameGene(geneA1, geneB2, GeneSize) || SameGene(geneA2, geneB1, GeneSize) || SameGene(geneA2, geneB2, GeneSize)) // Checking all the possible combinations of genes for A being related to B
    {
        OutputFile << "A is related to B." << endl; // output that A is related to B if true
    }
    
    if(SameGene(geneA1, geneC1, GeneSize) || SameGene(geneA1, geneC2, GeneSize) || SameGene(geneA2, geneC1, GeneSize) || SameGene(geneA2, geneC2, GeneSize)) // Checking all the possible combinations of genes for A being related to C
    {
        OutputFile << "A is related to C." << endl; // output that A is related to C if true
    }
    
    if(SameGene(geneA1, geneD1, GeneSize) || SameGene(geneA1, geneD2, GeneSize) || SameGene(geneA2, geneD1, GeneSize) || SameGene(geneA2, geneD2, GeneSize)) // Checking all the possible combinations of genes for A being related to D
    {
        OutputFile << "A is related to D." << endl; // output that A is related to D if true
    }
    
    if(SameGene(geneB1, geneC1, GeneSize) || SameGene(geneB1, geneC2, GeneSize) || SameGene(geneB2, geneC1, GeneSize) || SameGene(geneB2, geneC2, GeneSize)) // Checking all the possible combinations of genes for B being related to C
    {
        OutputFile << "B is related to C." << endl; // output that B is related to C if true
    }
    
    if(SameGene(geneB1, geneD1, GeneSize) || SameGene(geneB1, geneD2, GeneSize) || SameGene(geneB2, geneD1, GeneSize) || SameGene(geneB2, geneD2, GeneSize)) // Checking all the possible combinations of genes for B being related to D
    {
        OutputFile << "B is related to D." << endl; // output that B is related to D if true
    }
    
    if(SameGene(geneC1, geneD1, GeneSize) || SameGene(geneC1, geneD2, GeneSize) || SameGene(geneC2, geneD1, GeneSize) || SameGene(geneC2, geneD2, GeneSize)) // Checking all the possible combinations of genes for C being related to D
    {
        OutputFile << "C is related to D." << endl; // output that C is related to D if true
    }
    
    InputFile.close(); // close the input file
    OutputFile.close(); // close the output file
    
    return 0; // return 0
}

bool SameGene(char gene1[], char gene2[], int GeneSize)
// function definition with the 3 parameters
{
    for(int i = 0; i < GeneSize; i++)
    // as long as we are below the gene size (defined above)
    {
        if(gene1[i] != gene2[i])
            // compare the genes to each other (that were called as arguments during the function call)
        {
            return false;
            // if at any point they are not the same return false (the genes are not the same)
        }
    }
    return true;
    // if all the gene's chars are correct then they are the same return true
}
