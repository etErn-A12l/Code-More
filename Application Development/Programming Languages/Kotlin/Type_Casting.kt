fun main() {
    // Casting from same data Type
    val name1: Any = "Sreejan"
    val name2: String = name1 as String
    println(name2)

    // Casting from different data Typr (Though will not work)
    val num: Int = 90
    val num2: Long? = num as? Long
    println(num2)
}
