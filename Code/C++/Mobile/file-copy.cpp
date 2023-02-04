#include <stdio.h>
#include <stdlib.h>

int main()
{
   char ch, source_file[20], target_file[20];
   FILE *source, *target;
 
   printf("Enter name of file to copy\n");
   fgets(source_file, sizeof(source_file), stdin);
 
   source = fopen(source_file, "r");
 
   if( source == NULL )
   {
      printf("Failed to open source file\n");
      exit(EXIT_FAILURE);
   }
 
   printf("Enter name of target file\n");
   fgets(target_file, sizeof(target_file), stdin);
 
   target = fopen(target_file, "w");
 
   if( target == NULL )
   {
      printf("Failed to open target file\n");
      fclose(source);
      exit(EXIT_FAILURE);
   }
 
   while( ( ch = fgetc(source) ) != EOF )
   {
      if(fputc(ch, target) == EOF)
      {
         printf("Failed to write to target file\n");
         break;
      }
   }
 
   printf("File copied successfully.\n");
 
   if(fclose(source) == EOF)
   {
      printf("Failed to close source file\n");
   }
   
   if(fclose(target) == EOF)
   {
      printf("Failed to close target file\n");
   }
 
   return 0;
}
