using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace ConnectionDB {
    public class Provider {
        SqlConnection Connection { get; set; }        
        static string ConnectionString = @"Data Source=DESKTOP-SHA2DUP\SQLEXPRESS;Initial Catalog=Quan_Ly_Giao_Dich;Integrated Security=True";
        public void Connect() {
            try {
                if (Connection == null) {
                    Connection = new SqlConnection(ConnectionString);
                }
                if (Connection.State != ConnectionState.Closed) {
                    Connection.Close();
                }
                Connection.Open();
                    Console.WriteLine(Connection.State.ToString());
            } catch (SqlException ex) {
                throw ex;
            }
        }//End Connection.

        public void Disconnect() {
            if (Connection != null && Connection.State == ConnectionState.Open) {
                Connection.Close();
            }
            Console.WriteLine(Connection.State.ToString());
        }//End Disconnection.

        public int ExecuteNonQuery(CommandType cmdType, string strSql,
            params SqlParameter[] parameter) {
            try {
               SqlCommand command = Connection.CreateCommand();
                command.CommandText = strSql;
                command.CommandType = cmdType;
                if (parameter != null && parameter.Length > 0) {
                    command.Parameters.AddRange(parameter);                    
                }
                int nRow = command.ExecuteNonQuery();
                return nRow;
            } catch (Exception ex) {
                throw ex;
            }
        }

        public void Insert() {
            string strSql = "insert GiaoDich values(@MaGD, @ThoiGianGD)";

            Provider provider = new Provider();
            provider.Connect();

            provider.ExecuteNonQuery(CommandType.Text, strSql,
                new SqlParameter { ParameterName = "@MaGD", Value= "GD111"},
                new SqlParameter { ParameterName = "@ThoiGianGD", Value = "2/12/2017"});
            provider.Disconnect();
        }
    }
}
