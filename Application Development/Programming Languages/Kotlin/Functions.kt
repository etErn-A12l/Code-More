fun main() {
    val a: Int = 90
    val b: Int = 40

    println(addTwoNum(a, b))

    printUserName("Sreejan")
}

fun addTwoNum(a: Int, b: Int): Int {
    return a + b
}

fun printUserName(nm: String): Unit{
    println(nm)
}