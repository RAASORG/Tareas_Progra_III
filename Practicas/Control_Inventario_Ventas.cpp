# include <iostream>
# include <list>
# include <iomanip>
# include <limits>
# include <boost/multiprecision/cpp_dec_float.hpp>
# include <fstream>
# include <nlohmann/json.hpp>
# include <filesystem>

using namespace std;
using namespace boost::multiprecision;
using json = nlohmann::json;
using namespace std::filesystem;

class DetalleTransaccion
{
public:
    string producto;
    int cantidad;
    cpp_dec_float_50 precio_unitario;
    cpp_dec_float_50 subtotal;

    DetalleTransaccion(string xproducto, int xcantidad, cpp_dec_float_50 xprecio_unitario)
        : producto(xproducto), cantidad(xcantidad), precio_unitario(xprecio_unitario), subtotal(xcantidad * xprecio_unitario) {}
};

class Inventario
{
private:
    string producto;
    int cantidad;
    cpp_dec_float_50 precio_costo;
    cpp_dec_float_50 precio_venta;
    cpp_dec_float_50 ganancia_bruta;

public:
    Inventario(string xproducto, int xcantidad, cpp_dec_float_50 xprecio_costo, cpp_dec_float_50 xprecio_venta) :
        producto(xproducto), cantidad(xcantidad), precio_costo(xprecio_costo), precio_venta(xprecio_venta), ganancia_bruta(xprecio_venta - xprecio_costo) {}

    static void mostrarProductos(const list<Inventario> &inventario)
    {
        cpp_dec_float_50 total_cantidad = 0, total_costo = 0, total_venta = 0, total_ganancia = 0;
        
        cout << left << setw(15) << "Producto" << setw(10) << "Cantidad" << setw(15) << "Costo Unitario"
             << setw(15) << "Venta Unitaria" << setw(15) << "Total Costo" << setw(15) << "Total Venta" << setw(15) << "Ganancia" << endl;
        cout << string(100, '-') << endl;
        
        for (const auto &p : inventario)
        {
            cpp_dec_float_50 total_costo_producto = p.cantidad * p.precio_costo;
            cpp_dec_float_50 total_venta_producto = p.cantidad * p.precio_venta;
            cpp_dec_float_50 total_ganancia_producto = total_venta_producto - total_costo_producto;
            
            cout << left << setw(15) << p.producto << setw(10) << p.cantidad << setw(15) << p.precio_costo
                 << setw(15) << p.precio_venta << setw(15) << total_costo_producto << setw(15) << total_venta_producto
                 << setw(15) << total_ganancia_producto << endl;
            
            total_cantidad += p.cantidad;
            total_costo += total_costo_producto;
            total_venta += total_venta_producto;
            total_ganancia += total_ganancia_producto;
        }
        
        cout << string(100, '-') << endl;
        cout << left << setw(15) << "TOTAL" << setw(10) << total_cantidad << setw(15) << "-"
             << setw(15) << "-" << setw(15) << total_costo << setw(15) << total_venta << setw(15) << total_ganancia << endl;
    }

    static void exportarInventarioJSON(const list<Inventario> &inventario, const string &ruta)
    {
        json j;
        cpp_dec_float_50 total_cantidad = 0, total_costo = 0, total_venta = 0, total_ganancia = 0;

        for (const auto &p : inventario)
        {
            cpp_dec_float_50 total_costo_producto = p.cantidad * p.precio_costo;
            cpp_dec_float_50 total_venta_producto = p.cantidad * p.precio_venta;
            cpp_dec_float_50 total_ganancia_producto = total_venta_producto - total_costo_producto;

            j["productos"].emplace_back(json{
                {"producto", p.producto},
                {"cantidad", p.cantidad},
                {"precio_costo", p.precio_costo.str()},
                {"precio_venta", p.precio_venta.str()},
                {"total_costo", total_costo_producto.str()},
                {"total_venta", total_venta_producto.str()},
                {"ganancia", total_ganancia_producto.str()}
            });

            total_cantidad += p.cantidad;
            total_costo += total_costo_producto;
            total_venta += total_venta_producto;
            total_ganancia += total_ganancia_producto;
        }

        j["totales"] = {
            {"cantidad_total", total_cantidad.str()},
            {"total_costo", total_costo.str()},
            {"total_venta", total_venta.str()},
            {"ganancia_total", total_ganancia.str()}
        };

        string escritorio = getenv("USERPROFILE") + string("\\Desktop\\BD");
        create_directories(escritorio);
        string rutaCompleta = escritorio + "\\inventario.json";

        ofstream archivo(rutaCompleta);
        if (archivo.is_open())
            {
                archivo << j.dump(4);
                archivo.close();
            }
    }

    static void validarEntrada(int &valor)
    {
        while (!(cin >> valor))
        {
            cout << "Entrada invalida. Solo se permiten numeros. Intente de nuevo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    static void validarEntrada(cpp_dec_float_50 &valor)
    {
        while (!(cin >> valor))
        {
            cout << "Entrada invalida. Solo se permiten numeros. Intente de nuevo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    static void agregarProducto(list<Inventario> &inventario)
    {
        string nombre;
        int cantidad;
        cpp_dec_float_50 precio_costo, precio_venta;
        
        cout << "Ingrese nombre del producto: ";
        cin >> nombre;
        cout << "Ingrese cantidad: ";
        validarEntrada(cantidad);
        cout << "Ingrese precio de costo: ";
        validarEntrada(precio_costo);
        cout << "Ingrese precio de venta: ";
        validarEntrada(precio_venta);
        
        inventario.emplace_back(nombre, cantidad, precio_costo, precio_venta);
        cout << "Producto agregado con exito!" << endl;
    }

    static void eliminarProducto(list<Inventario> &inventario)
    {
        string nombre;
        cout << "Ingrese el nombre del producto a eliminar: ";
        cin >> nombre;
        
        auto it = find_if(inventario.begin(), inventario.end(), [&](const Inventario &p) { return p.producto == nombre; });
        
        if (it != inventario.end())
        {
            inventario.erase(it);
            cout << "Producto eliminado con exito!" << endl;
        }
        else
        {
            cout << "Producto no encontrado." << endl;
        }
    }

    static void modificarProducto(list<Inventario> &inventario)
    {
        string nombre;
        cout << "Ingrese el nombre del producto a modificar: ";
        cin >> nombre;
        
        for (auto &p : inventario)
        {
            if (p.producto == nombre)
            {
                cout << "Ingrese nueva cantidad: ";
                validarEntrada(p.cantidad);
                cout << "Ingrese nuevo precio de costo: ";
                validarEntrada(p.precio_costo);
                cout << "Ingrese nuevo precio de venta: ";
                validarEntrada(p.precio_venta);
                cout << "Producto modificado con exito!" << endl;
                return;
            }
        }
        cout << "Producto no encontrado." << endl;
    }

    static void menuInventario(list<Inventario> &inventario)
    {
        int opcion;
        do
        {
            cout << "\nMENU INVENTARIO" << endl;
            cout << "1. Agregar producto" << endl;
            cout << "2. Mostrar productos" << endl;
            cout << "3. Eliminar producto" << endl;
            cout << "4. Modificar producto" << endl;
            cout << "5. Volver al menu principal" << endl;
            cout << "Seleccione una opcion: ";
            validarEntrada(opcion);
            
            switch (opcion)
            {
            case 1:
                agregarProducto(inventario);
                exportarInventarioJSON(inventario, "inventario.json");
                break;
            case 2:
                mostrarProductos(inventario);
                break;
            case 3:
                eliminarProducto(inventario);
                break;
            case 4:
                modificarProducto(inventario);
                break;
            }
        } while (opcion != 5);
    }
};

void menu()
{
    int opcion;
    list<Inventario> inventario;
    do
    {
        cout << "\033[2J\033[H";
        cout << "\nMENU PRINCIPAL" << endl;
        cout << "1. INVENTARIO" << endl;
        cout << "2. COMPRA" << endl;
        cout << "3. VENTA" << endl;
        cout << "4. SALIR" << endl;
        cout << "Seleccione una opcion: ";
        Inventario::validarEntrada(opcion);
        
        switch (opcion)
        {
        case 1:
            Inventario::menuInventario(inventario);
            break;
        case 2:
            Inventario::agregarProducto(inventario);
            break;
        }
    } while (opcion != 4);
}

int main()
{
    menu();
    return 0;
}