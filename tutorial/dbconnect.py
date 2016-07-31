import MySQLdb
def connection():
    conn = MySQLdb.connect(host="localhost",
                           user="root",
                           passwd="b",
                           db = "tutorialdb")
    c = conn.cursor()

    return c, conn