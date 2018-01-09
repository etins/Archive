package interfaces.filters;

public class BandPass extends Filter {
    double lowCutoff, hightCutoff;

    public BandPass(double lowCut, double hightCut) {
        lowCutoff = lowCut;
        hightCutoff = hightCut;
    }

    @Override
    public Waveform process(Waveform input) {
        return input;
    }
}
