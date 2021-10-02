import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.util.*

fun main(args: Array<String>) {
    // main code goes here
    
}

    fun sort(a: IntArray) {
        val l = ArrayList<Int>()
        for (i in a) l.add(i)
        Collections.sort(l)
        for (i in a.indices) a[i] = l[i]
    }

    internal class FastScanner {
        var br = BufferedReader(InputStreamReader(System.`in`))
        var st = StringTokenizer("")
        operator fun next(): String {
            while (!st.hasMoreTokens()) try {
                st = StringTokenizer(br.readLine())
            } catch (e: IOException) {
                e.printStackTrace()
            }
            return st.nextToken()
        }

        fun nextInt(): Int {
            return next().toInt()
        }

        fun readArray(n: Int): IntArray {
            val a = IntArray(n)
            for (i in 0 until n) a[i] = nextInt()
            return a
        }

        fun nextLong(): Long {
            return next().toLong()
        }
    }
