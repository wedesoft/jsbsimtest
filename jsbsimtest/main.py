import jsbsim


def main():
    fdmex = jsbsim.FGFDMExec('')
    fdmex.load_model('Shuttle')


if __name__ == "__main__":
    main()
