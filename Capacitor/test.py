import serial
import matplotlib.pyplot as plt

puerto = 'COM9'
baudrate = 9600

ser = serial.Serial(puerto, baudrate, timeout=1)
valores_carga = []
valores_descarga = []

tiempo_carga = None
tiempo_descarga = None

print("Leyendo datos desde Arduino...")

try:
    leyendo_carga = True
    while True:
        linea = ser.readline().decode().strip()
        if linea == "---":
            break
        if linea.isdigit():
            valor = int(linea)
            if leyendo_carga:
                valores_carga.append(valor)
            else:
                valores_descarga.append(valor)
            # Detectar transición de carga a descarga
            if leyendo_carga and len(valores_carga) >= 2 and valor >= 1000:
                tiempo_carga = len(valores_carga) * 10  # 10 ms por muestra
                leyendo_carga = False
    tiempo_descarga = len(valores_descarga) * 10  # También 10 ms por muestra
except KeyboardInterrupt:
    print("Lectura interrumpida.")
finally:
    ser.close()

# Mostrar tiempos en consola (opcional)
print(f"⏱ Tiempo de carga: {tiempo_carga} ms")
print(f"⏱ Tiempo de descarga: {tiempo_descarga} ms")

# Preparar ejes X en milisegundos
tiempo_x_carga = [i * 10 for i in range(len(valores_carga))]
tiempo_x_descarga = [i * 10 for i in range(len(valores_descarga))]

# 🟢 Graficar con tiempos en la leyenda
plt.plot(tiempo_x_carga, valores_carga,
         label=f"Carga ({tiempo_carga} ms)", marker='o')
plt.plot(tiempo_x_descarga, valores_descarga,
         label=f"Descarga ({tiempo_descarga} ms)", marker='x')
plt.title("Curva de carga y descarga del condensador")
plt.xlabel("Tiempo (ms)")
plt.ylabel("Voltaje (ADC 0-1023)")
plt.legend()
plt.grid()
plt.tight_layout()
plt.show()
