fun main(){
    printNameLength("Sreejan",null)
}

fun printNameLength(firstName: String?, lastName: String?) {

    if(firstName!= null) 
    
    {
        println("Name: ${firstName.length} ${lastName!!.length}")
    }
}