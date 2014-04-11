%% Set figure’s dimensions

% we set the units of the measures used through the file
%
% [ inches | centimeters | normalized | points | {pixels} | characters ]
set(gcf, 'Units', 'centimeters');

% we set the position and dimension of the figure ON THE SCREEN
%
% NOTE: measurement units refer to the previous settings!
%afFigurePosition = [1 1 20 5.5];        % [pos_x pos_y width_x width_y]
%seta a posição e as dimensões da figura NA TELA
phi=0.5*(1+sqrt(5));
%figuras normais
height=1/phi;
width=1;
%figuras compridas
%height=1/phi;
%width=2;
scale=20;
xpos=2;
ypos=2;
afFigurePosition= [xpos ypos scale*width scale*height]; %[pos_x pos_y width_x width_y]
set(gcf, 'Position', afFigurePosition); % [left bottom width height]

% we link the dimension of the figure ON THE PAPER in such a way that
% it is equal to the dimension on the screen
%
% ATTENTION: if PaperPositionMode is not 'auto' the saved file
% could have different dimensions from the one shown on the screen!
set(gcf, 'PaperPositionMode', 'auto');

% in order to make matlab to do not "cut" latex-interpreted axes labels
set(gca, 'Units','normalized',... %
    'Position',[0.15 0.2 0.75 0.7]);

%% Set axes properties

% general properties
iFontSize = 16;
strFontUnit = 'points';         % [{points} | normalized | inches | centimeters | pixels]
strFontName = 'Times';          % [Times | Courier | ] TODO complete the list
strFontWeight = 'bold';       % [light | {normal} | demi | bold]
strFontAngle = 'normal';        % [{normal} | italic | oblique] ps: only for axes
strInterpreter = 'tex';       % [{tex} | latex]
fLineWidth = 3.0;               % width of the line of the axes

% note: it is quite difficult to use the "latex" interpreter for the ticks;
% if absolutely needed google for "format_ticks.m" by Alexander Hayes
set(gca, ...
    ... 'Position', [1 1 20 10], ... TODO
    ... 'OuterPosition', [1 1 20 10], ... TODO
    ...
    'XGrid', 'off', ...              [on | {off}]
    'YGrid', 'off', ...              [on | {off}]
    'GridLineStyle', ':', ...       [- | -- | {:} | -. | none]
    'XMinorGrid', 'off' , ...       [on | {off}]
    'YMinorGrid', 'off', ...        [on | {off}]
    'MinorGridLineStyle', ':', ...  [- | -- | {:} | -. | none]
    ...
    ... 'XTick', [], ...
    'XMinorTick', 'on', ...           [on | {off}]
    'YTick', [], ...
    'YMinorTick', 'off', ...            [on | {off}]
    'TickDir', 'out', ...               [{in} | out] inside or outside (for 2D)
    'TickLength', [.025 .05], ...        length of the ticks
    ...
    'XColor', [.1 .1 .1], ...           color of x axis
    'YColor', [.1 .1 .1], ...           color of y axis
    'XAxisLocation', 'bottom', ...      where labels have to be printed [top | {bottom}]
    'YAxisLocation', 'left', ...        where labels have to be printed [left | {right}]
    'XDir', 'normal', ...               axis increasement direction [{normal} | reverse]
    'YDir', 'normal', ...               axis increasement direction [{normal} | reverse]
    'Box', 'off', ...
    ...
    'FontName', strFontName, ...        kind of fonts of labels
    'FontSize', iFontSize, ...          size of fonts of labels
    'FontUnits', strFontUnit, ...       units of the size of fonts
    'FontWeight', strFontWeight, ...    weight of fonts of labels
    'FontAngle', strFontAngle, ...      inclination of fonts of labels
    ...
    'LineWidth', fLineWidth);           % width of the line of the axes

%% Set axes labels

% fonts properties
iFontSize = 16;
strFontUnit = 'points';         % [{points} | normalized | inches | centimeters | pixels]
strFontName = 'Times';          % [Times | Courier | ] TODO complete the list
strFontWeight = 'bold';       % [light | {normal} | demi | bold]
strFontAngle = 'bold';        % [{normal} | italic | oblique] ps: only for axes
strInterpreter = 'tex';       % [{tex} | latex]

strXLabel = get(gca,'XLabel');
strYLabel = get(gca,'YLabel');

fXLabelRotation = 0.0;
fYLabelRotation = 90.0;
set( strXLabel, ...
    'FontName', strFontName, ...
    'FontUnit', strFontUnit, ...
    'FontSize', iFontSize, ...
    'FontWeight', strFontWeight, ...
    'Interpreter', strInterpreter);
%
set( strYLabel, ...
    'FontName', strFontName, ...
    'FontUnit', strFontUnit, ...
    'FontSize', iFontSize, ...
    'FontWeight', strFontWeight, ...
    'Interpreter', strInterpreter);
%
set(get(gca, 'XLabel'), 'Rotation', fXLabelRotation);
set(get(gca, 'YLabel'), 'Rotation', fYLabelRotation);

% in order to make matlab to do not "cut" latex-interpreted axes labels
set(gca, 'Units', 'normalized', ...
    'Position', [0.15 0.2 0.75 0.7]);

%% Set plots properties

% we set the plots properties
%
% notes:
% - each property is actually an array of properties;
%
% line styles: [{-} | -- | : | -.]
% marker types: [+ | o | * | . | x | square | diamond | > | ...
% ... < | ^ | v | pentagram | hexagram | {none}]
%

% -- lines
afPlotLineWidth = [2.0, 1.5];
astrPlotLineStyle = [{'-'}, {':'}];                % NOTE: do not insert '.-' but '-.'
aafPlotLineColor = [[0.1 0.1 0.1] ; [0.2 0.2 0.2]]; % RGB
%
% -- markers
setMarker = 0;
aiPlotMarkerSize = [25, 21]; % in points
astrPlotMarkerType = [{'.'}, {'x'}];
aafPlotMarkerFaceColor = [[0.1 0.1 0.1] ; [0.2 0.2 0.2]]; % RGB
aafPlotMarkerEdgeColor = [[0.3 0.3 0.3] ; [0.4 0.4 0.4]]; % RGB

% we want to plot several curves
hold on;
%
% here you can plot several plots (each can have its properties)
% note: it is convenient to store the handles to the single plots
% in order to easily manage legends
%
h_red = findobj('Type','line','Color','r');

for (ii=1:length(h_red))
    set(h_red(ii), ...
        'LineStyle', astrPlotLineStyle{1}, ...
        'LineWidth', afPlotLineWidth(1), ...
        'Color', aafPlotLineColor(1,:));
    
    if (setMarker)
        set(h_red(ii), ...
            'Marker', astrPlotMarkerType{1}, ...
            'MarkerSize', aiPlotMarkerSize(1), ...
            'MarkerFaceColor', aafPlotMarkerFaceColor(1,:), ...
            'MarkerEdgeColor', aafPlotMarkerEdgeColor(1,:));
    end
end

h_blue = findobj('Type','line','Color','blue');

for (jj=1:length(h_blue))
    set(h_blue(jj), ...
        'LineStyle', astrPlotLineStyle{2}, ...
        'LineWidth', afPlotLineWidth(2), ...
        'Color', aafPlotLineColor(2,:));
    
    if (setMarker)
        set(h_blue(ii), ...
            'Marker', astrPlotMarkerType{1}, ...
            'MarkerSize', aiPlotMarkerSize(1), ...
            'MarkerFaceColor', aafPlotMarkerFaceColor(1,:), ...
            'MarkerEdgeColor', aafPlotMarkerEdgeColor(1,:));
    end
end

%% Set annotation properties

% Properties
iFontSize = 16;
strFontUnit = 'points';         % [{points} | normalized | inches | centimeters | pixels]
strFontName = 'Times';          % [Times | Courier | ] TODO complete the list
strFontWeight = 'bold';       % [light | {normal} | demi | bold]
strFontAngle = 'normal';        % [{normal} | italic | oblique] ps: only for axes
strInterpreter = 'tex';       % [{tex} | latex]

% we use normalized units of measure (i.e. figure reference system has coordinates
% between 0 and 1)
set(gcf, 'Units', 'normalized');
%

h_text = findobj('Type','text');

for (ii = 1:length(h_text))
    set( h_text(ii), ...
        'FontName', strFontName, ...
        'FontUnit', strFontUnit, ...
        'FontSize', iFontSize, ...
        'FontWeight', strFontWeight, ...
        'Interpreter', strInterpreter, ...
        'Color', 'black');

    str = get(h_text(ii), 'String');
    set(h_text(ii), 'String', strrep(str, 'N_{2DEG}=', '-')); 
    str = get(h_text(ii), 'String');
    set(h_text(ii), 'String', strrep(str, 'x', '\times')); 
    str = get(h_text(ii), 'String');
    set(h_text(ii), 'String', regexprep(str, '\\color{\w*}', ''));
end

% %% Save the figure
% 
% % here we select which output file extension we want
% bPrintOnFile_Pdf = 1; % [0 (false) 1 (true)]
% bPrintOnFile_Eps = 1; % [0 (false) 1 (true)]
% % we select the file path
% %
% % NOTE: do NOT insert extensions!
% %strFilePath = '../images/my_figure';
% strFilePath = 'c:\\my_figure';
% 
% % we select the printing resolution
% iResolution = 150;
% 
% % we select to crop or not the figure
% bCropTheFigure = 1; % [0 (false) 1 (true)]
% 
% % ATTENTION: if PaperPositionMode is not 'auto' the saved file
% % could have different dimensions from the one shown on the screen!
% set(gcf, 'PaperPositionMode', 'auto');
% 
% % saving on file: requires some checks
% if( bPrintOnFile_Pdf || bPrintOnFile_Eps )
%     %
%     % NOTE: if you want a .pdf with encapsulated fonts you need to save an
%     % .eps and then convert it => it is always necessary to produce the .eps
%     %
%     % if we want to crop the figure we do it
%     if( bCropTheFigure )
%         print('-depsc2', sprintf('-r%d', iResolution), strcat(strFilePath, '.eps'));
%     else
%         print('-depsc2', '-loose', sprintf('-r%d', iResolution), strcat(strFilePath, '.eps'));
%     end;
%     
%     % if we want the .pdf we produce it
%     if( bPrintOnFile_Pdf )
%         %
%         % here we convert the .eps encapsulating the fonts
%         system( ...
%             sprintf( ...
%             'epstopdf --gsopt=-dPDFSETTINGS=/prepress --outfile=%s.pdf %s.eps', ...
%             strFilePath, ...
%             strFilePath));
%         %
%     end;
%     %
%     % if we do not want the .eps we remove it
%     if( ~bPrintOnFile_Eps )
%         delete(sprintf('%s.eps', strFilePath));
%     end;
%     %
% end;% saving on file

%% ------------------------------------------------------------

% %% How to plot annotations
% % annotation type
% %
% % ------------------------------------------------------------------------
% % | kind of annotation | required arguments |
% % ------------------------------------------------------------------------
% % | line arrow doublearrow | starting_point ending_point |
% % | textbox ellipse rectangle | starting_point ending_point width height |
% % ------------------------------------------------------------------------
% strAnnotationType = 'line';
% %
% % arguments
% afStartingPoint = [1, 2];
% afEndingPoint = [8, 4];
% fWidth = 10; % could be not necessary
% fHeight = 3; % could be not necessary
% % (p1): we obtain the position of the axes inside the figure
% %
% % we use normalized units of measure (i.e. figure reference system has coordinates
% % between 0 and 1)
% set(gcf, 'Units', 'normalized');
% %
% afXAxisLimits = get(gca, 'XLim');
% afYAxisLimits = get(gca, 'YLim');
% %
% afAxesDimensionsAndPositions = get(gca, 'Position');
% fXAxisPosition = afAxesDimensionsAndPositions(1);
% fYAxisPosition = afAxesDimensionsAndPositions(2);
% fXAxisLength = afAxesDimensionsAndPositions(3);
% fYAxisLength = afAxesDimensionsAndPositions(4);
% 
% fXonYAxesRatio = fXAxisLength / fYAxisLength;
% %
% afFigurePosition = get(gcf, 'Position'); % [left bottom width height]
% fXonYDimensionRatio = afFigurePosition(3) / afFigurePosition(4);
% % (p2): convert the axes measurement units into the figure measurement units
% afStartingPoint_FU(1) = ( afStartingPoint(1) - afXAxisLimits(1) ) ...
%     / ( afXAxisLimits(2) - afXAxisLimits(1) ) ...
%     * fXAxisLength + fXAxisPosition;
% afStartingPoint_FU(2) = ( afStartingPoint(2) - afYAxisLimits(1) ) ...
%     / ( afYAxisLimits(2) - afYAxisLimits(1) ) ...
%     * fYAxisLength + fYAxisPosition;
% afEndingPoint_FU(1) = ( afEndingPoint(1) - afXAxisLimits(1) ) ...
%     / ( afXAxisLimits(2) - afXAxisLimits(1) ) ...
%     * fXAxisLength + fXAxisPosition;
% afEndingPoint_FU(2) = ( afEndingPoint(2) - afYAxisLimits(1) ) ...
%     / ( afYAxisLimits(2) - afYAxisLimits(1) ) ...
%     * fYAxisLength + fYAxisPosition;
% 
% % we plot the annotation
% handleToAnnotation1 = annotation( ...
%     ... handleToFigure, ... uncomment if necessary
%     strAnnotationType, ...
%     [afStartingPoint_FU(1) afEndingPoint_FU(1)], ...
%     [afStartingPoint_FU(2) afEndingPoint_FU(2)]); %... uncomment if necessary
% % fWidth, ... uncomment if necessary
% % fHeight); % uncomment if necessary
% 
% %% How to plot labels
% 
% % fonts properties
% iFontSize = 20;
% strFontUnit = 'points';     % [{points} | normalized | inches | centimeters | pixels]
% strFontName = 'Times';      % [Times | Courier | ] TODO complete the list
% strFontWeight = 'normal';   % [light | {normal} | demi | bold]
% strFontAngle = 'normal';    % [{normal} | italic | oblique] ps: only for axes
% strInterpreter = 'latex';   % [{tex} | latex | none]
% 
% % note: the xPosition and yPosition are referred in the "axes" units of measure
% text( xPosition, ...
%     yPosition, ...
%     'this is the text plotted', ...
%     'FontName', strFontName, ...
%     'FontSize', iFontSize, ...
%     'FontWeight', strFontWeight, ...
%     'Interpreter', strInterpreter);
% 
% %% How to set legends
% % we set the legend properties; note:
% %
% % Locations could be [N S E W {NE} NW SE SW NO SO EO WO NEO NWO SEO SWO B BO]
% % where the characters have the following meanings:
% % - N = North
% % - S = South
% % - E = East
% % - W = West
% % - O = Outside the plot
% % - B = Best (least conflict with data in plot)
% % OR you can also specify an 1-by-4 position vector ([left bottom width height])
% %
% % The following properties are inherited when specified in "set(gca, ...)":
% % - FontName
% % - FontSize
% % - FontUnits
% % - FontWeight
% % - FontAngle
% % - LineWidth
% %
% atArrayOfHandlesToLines = [handleToFirstLine; handleToSecondLine; handleToThirdLine];
% astrArrayOfLabels = [{'first line'}; {'second line'}; {'third line'}];
% %
% strLegendLocation = 'Best'; % combinations of N S E W B O or a vector
% strLegendOrientation = 'vertical'; % [{vertical} horizontal]
% %
% afEdgeColor = [0.0 0.0 0.0]; % RGB
% afTextColor = [0.0 0.0 0.0]; % RGB
% %
% strInterpreter = 'tex'; % [{tex} | latex | none]
% %
% %
% legend( atArrayOfHandlesToLines, ...
%     astrArrayOfLabels, ...
%     'Location', strLegendLocation, ...
%     'Orientation', strLegendOrientation, ...
%     'Box', 'off', ... [{on} off]
%     'Color', 'none', ... none => transparent
%     'EdgeColor', afEdgeColor, ...
%     'TextColor', afTextColor, ...
%     'Interpreter', strInterpreter);
% 
% %% How to save figures
% 
% % here we select which output file extension we want
% bPrintOnFile_Pdf = 1; % [0 (false) 1 (true)]
% bPrintOnFile_Eps = 1; % [0 (false) 1 (true)]
% % we select the file path
% %
% % NOTE: do NOT insert extensions!
% %strFilePath = '../images/my_figure';
% strFilePath = 'c:\\my_figure';
% % we select the printing resolution
% iResolution = 150;
% % we select to crop or not the figure
% bCropTheFigure = 1; % [0 (false) 1 (true)]
% % ATTENTION: if PaperPositionMode is not 'auto' the saved file
% % could have different dimensions from the one shown on the screen!
% set(gcf, 'PaperPositionMode', 'auto');
% % saving on file: requires some checks
% if( bPrintOnFile_Pdf || bPrintOnFile_Eps )
%     %
%     % NOTE: if you want a .pdf with encapsulated fonts you need to save an
%     % .eps and then convert it => it is always necessary to produce the .eps
%     %
%     % if we want to crop the figure we do it
%     if( bCropTheFigure )
%         print('-depsc2', sprintf('-r%d', iResolution), strcat(strFilePath, '.eps'));
%     else
%         print('-depsc2', '-loose', sprintf('-r%d', iResolution), strcat(strFilePath, '.eps'));
%     end;
%     
%     % if we want the .pdf we produce it
%     if( bPrintOnFile_Pdf )
%         %
%         % here we convert the .eps encapsulating the fonts
%         system( ...
%             sprintf( ...
%             'epstopdf --gsopt=-dPDFSETTINGS=/prepress --outfile=%s.pdf %s.eps', ...
%             strFilePath, ...
%             strFilePath));
%         %
%     end;
%     %
%     % if we do not want the .eps we remove it
%     if( ~bPrintOnFile_Eps )
%         delete(sprintf('%s.eps', strFilePath));
%     end;
%     %
% end;% saving on file